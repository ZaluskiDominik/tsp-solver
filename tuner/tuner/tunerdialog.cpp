#include "tunerdialog.h"
#include <QFileDialog>
#include <thread>
#include <cstdlib>
#include <fstream>

TunerDialog::TunerDialog(QWidget *parent)
    :QDialog(parent)
{
    ui.setupUi(this);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(onTimeUpdate()));
    QObject::connect(this, SIGNAL(stopTimer()), this, SLOT(onStopTimer()));
}

void TunerDialog::initParamRanges()
{
    params = QVector<ParamRange>{
        ParamRange{ "ants", static_cast<double>(ui.antsMin->value()),
            static_cast<double>(ui.antsMax->value()), static_cast<double>(ui.antsStep->value()) },
        ParamRange{ "alpha", ui.alphaMin->value(), ui.alphaMax->value(), ui.alphaStep->value() },
        ParamRange{ "betha", ui.bethaMin->value(), ui.bethaMax->value(), ui.bethaStep->value() },
        ParamRange{ "evapor", static_cast<double>(ui.evapMin->value()) / 100.0,
            static_cast<double>(ui.evapMax->value()) / 100.0, static_cast<double>(ui.evapStep->value()) / 100.0 }
    };
}

void TunerDialog::computeAllParamsSets()
{
    do
    {
        runInstance();
    }
    while(nextParamsSet());

    allParamsExecuted();
}

bool TunerDialog::nextParamsSet()
{
    params[0].val += params[0].step;
    for (int i = 0 ; params[i].val > params[i].maxVal ; i++)
    {
        //if last parameter's value overflows its max value, all sets were generated
        if (i == params.size() - 1)
            return false;

        //reset current's parameters's value to its min value
        params[i].val = params[i].minVal;
        //increase next parameter's value by one step
        params[i + 1].val += params[i + 1].step;
    }

    return true;
}

void TunerDialog::runInstance()
{
    //prepare shell command to run
    QString cmd = "../../tsp ant " + ui.instanceFile->text() + " out=dist time=" +
            QString::number(ui.timeLimit->value() * 1000);
    //concatenate parameters set
    for (auto param : params)
        cmd += " " + param.name + "=" + QString::number(param.val);

    //run command in new process
    FILE* f = popen(cmd.toStdString().c_str(), "r");

    //get output of ran process from pipe
    char result[30];
    fgets(result, 30, f);
    paramsSetResultAvailable(atoi(result));

    //close pipe
    pclose(f);
}

void TunerDialog::paramsSetResultAvailable(int distance)
{
    //add result to vector
    results.push_back( ParamsSetResult{
        static_cast<int>(params[0].val), params[1].val, params[2].val,
        params[3].val, distance
    });
}

void TunerDialog::allParamsExecuted()
{
    //enable start button
    ui.startBtn->setEnabled(true);
    //stop counting time
    emit stopTimer();

    //sort results by distance
    std::sort(results.begin(), results.end(),
              [](ParamsSetResult& a, ParamsSetResult& b) { return a.distance < b.distance; });

    //save all results to file
    std::ofstream file(ui.outFile->text().toStdString());
    if (file.is_open())
    {
        //output column names
        file << "distance numAnts alpha betha evaporationRate\n";

        //output record values
        for (const auto& result : results)
        {
            file << result.distance << " " << result.numAnts << " " << result.alpha <<
                    " " << result.betha << " " << result.evaporationRate << "\n";
        }
    }
}

void TunerDialog::on_startBtn_clicked()
{
    //if instace file ot output file weren't choosen do nothing
    if (ui.instanceFile->text() == "" || ui.outFile->text() == "")
        return;

    //disable start button and initialize first parameters set
    ui.startBtn->setDisabled(true);
    initParamRanges();

    //run function in new thread running program implementing ant colony with different parameters
    std::thread t(&TunerDialog::computeAllParamsSets, this);
    t.detach();

    //start counting time
    timer.start(1000);
}

void TunerDialog::on_chooseInstBtn_clicked()
{
    //get instance's path from QFileDialog
    QString path = QFileDialog::getOpenFileName(this, "Choose instance");
    ui.instanceFile->setText(path);
}

void TunerDialog::onTimeUpdate()
{
    //increment number of seconds elapsed from start
    ui.totalTime->setText( QString::number( ui.totalTime->text().toInt() + 1 ) );
}

void TunerDialog::onStopTimer()
{
    timer.stop();
}

void TunerDialog::on_chooseOutFileBtn_clicked()
{
    //get output file's path from QFileDialog
    QString path = QFileDialog::getOpenFileName(this, "Choose output file");
    ui.outFile->setText(path);
}

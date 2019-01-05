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
        ParamRange{ static_cast<double>(ui.antsMin->value()),
            static_cast<double>(ui.antsMax->value()), static_cast<double>(ui.antsStep->value()) },
        ParamRange{ ui.alphaMin->value(), ui.alphaMax->value(), ui.alphaStep->value() },
        ParamRange{ ui.bethaMin->value(), ui.bethaMax->value(), ui.bethaStep->value() },
        ParamRange{ static_cast<double>(ui.evapMin->value()) / 100.0,
            static_cast<double>(ui.evapMax->value()) / 100.0, static_cast<double>(ui.evapStep->value()) / 100.0 }
    };
}

void TunerDialog::disableGeneralOptions(bool yes)
{
    ui.chooseInstBtn->setDisabled(yes);
    ui.chooseOutFileBtn->setDefault(yes);
    ui.numRuns->setDisabled(yes);
    ui.numThreads->setDisabled(yes);
    ui.timeLimit->setDisabled(yes);
}

void TunerDialog::computeAllParamsSets()
{
    //run all possible parameters set in tsp solver
    do
    {
        for (int i = 0 ; i < ui.numRuns->value() ; i++)
        {
            //wait until some slot on thread will be available
            while ( !numThreads );

            //decrement number of available thread
            numThreads--;

            //run new thread with currently generated params set
            ParamsSet set{static_cast<int>(params[0].val), params[1].val, params[2].val, params[3].val};
            std::thread t(&TunerDialog::runInstance, this, set);
            t.detach();
        }
    }
    while(nextParamsSet());

    //wait for all threads done executing tsp solver process
    while(numThreads != ui.numRuns->value());

    //all possible params sets were generated, store result in file
    allParamsExecuted();
}

int TunerDialog::calcNumPossibleSets()
{
    int num = 1;

    //number of possible params sets = multiplication of number of possible values beetwen
    //min value and max value of each parameter in vector
    for (const auto& param : params)
    {
        num *= (param.maxVal > param.minVal) ?
                    static_cast<int>( (param.maxVal - param.minVal) / param.step ) + 1 : 1;
    }

    return num;
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

void TunerDialog::runInstance(ParamsSet set)
{
    //prepare shell command to run
    QString cmd = "../../tsp ant " + ui.instanceFile->text() + " out=dist time=" +
            QString::number(ui.timeLimit->value() * 1000);
    //concatenate parameters set
    cmd += " ants=" + QString::number(set.numAnts) + " alpha=" + QString::number(set.alpha)
            + " betha=" + QString::number(set.betha) + " evapor=" + QString::number(set.evaporationRate);

    //run command in new process
    FILE* f = popen(cmd.toStdString().c_str(), "r");

    //wait for process to end execution
    //get output of ran process from pipe
    char result[30];
    fgets(result, 30, f);

    //close pipe
    pclose(f);

    //process new result of execution tsp solver
    paramsSetResultAvailable(atoi(result));
}

void TunerDialog::paramsSetResultAvailable(int distance)
{
    //lock resources
    std::lock_guard<std::mutex> lock(mutex);

    //increment number of already run tsp solver processes
    numAlreadyRun++;

    //update progress bar
    updateProgressBar();

    //add new result to vector
    results.push_back( ParamsSetResult{
        { static_cast<int>(params[0].val), params[1].val, params[2].val, params[3].val },
             distance
    });

    //increment number of available thread
    numThreads++;
}

void TunerDialog::allParamsExecuted()
{
    //enable start button
    ui.startBtn->setEnabled(true);
    disableGeneralOptions(false);
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
            file << result.distance << " " << result.set.numAnts << " " << result.set.alpha <<
                    " " << result.set.betha << " " << result.set.evaporationRate << "\n";
        }
    }
}

void TunerDialog::updateProgressBar()
{
    ui.progressBar->setValue(static_cast<int>(
        static_cast<double>(numAlreadyRun) / static_cast<double>(numTotalRuns) * 100 ));
}

void TunerDialog::on_startBtn_clicked()
{
    //if instace file ot output file weren't choosen do nothing
    if (ui.instanceFile->text() == "" || ui.outFile->text() == "")
        return;

    //clear vector with results
    results.clear();
    //reset total time elapsed from start
    ui.elapsedTime->setText("0");
    ui.progressBar->setValue(0);
    numAlreadyRun = 0;

    //disable start button and initialize parameters set structures
    ui.startBtn->setDisabled(true);
    disableGeneralOptions();
    initParamRanges();

    //how many times tsp solver process will be executed
    numTotalRuns = calcNumPossibleSets() * ui.numRuns->value();

    //number of thread that will be used while executing parameters in tsp solver
    numThreads = ui.numThreads->value();

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
    ui.elapsedTime->setText( QString::number( ui.elapsedTime->text().toInt() + 1 ) );
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

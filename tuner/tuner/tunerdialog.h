#ifndef TUNERDIALOG_H
#define TUNERDIALOG_H

#include <QDialog>
#include "ui_tunerdialog.h"
#include <QVector>
#include <QTimer>

class TunerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TunerDialog(QWidget *parent = nullptr);

private:
    struct ParamRange;
    struct ParamsSetResult;

    Ui::TunerDialog ui;

    //number of time each parameters set will be run
    int numParamsSetRuns;

    //total number of runs of tsp solver program
    //it's a (number of possible parameters sets) * (number of runs for each set)
    int numTotalRuns;

    //timer counting time elapsed from start of running ant colony tsp solver with different parameters
    QTimer timer;

    //array of parameters ranges for tsp ant colony algorithm
    QVector<ParamRange> params;

    //vector with result of running ant colony for each generated parameters set
    QVector<ParamsSetResult> results;

    //append parameters to params array
    void initParamRanges();

    //disables buttons for choosing output file and instance
    void disableChoosingBtns(bool yes = true);

    //generates all possible parameters sets for solving tsp instance with ant colony algorithm
    void computeAllParamsSets();

    //calculates number of possible parameters sets that can be generated from params vector
    int calcNumPossibleSets();

    //computes next parameters set
    //returns false if all parameters sets were generated
    bool nextParamsSet();

    //runs ant colony algorithm with given parameters set
    void runInstance();

    //result of ran ant colony algorithm with given params is available
    void paramsSetResultAvailable(int distance);

    //tsp solver was ran with all generated parameters sets
    void allParamsExecuted();

    //updates progress of progress bar according to ratio numRunsExecuted / numTotalRuns
    void updateProgressBar(int numRunsExecuted);

private slots:
    //start button clicked
    void on_startBtn_clicked();

    //choose instance button clicked
    void on_chooseInstBtn_clicked();

    //choose output file button clicked
    void on_chooseOutFileBtn_clicked();

    //timer fired off timeout signal after one seconds
    void onTimeUpdate();

    //stop of timer has been requested from another thread
    void onStopTimer();

signals:
    void stopTimer();
};

struct TunerDialog::ParamRange
{
    ParamRange() = default;
    ParamRange(QString name, double minVal, double maxVal, double step)
    {
        this->name = name;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->step = step;
        this->val = minVal;
    }

    QString name;
    double minVal, maxVal;
    double step;
    double val;
};

struct TunerDialog::ParamsSetResult
{
    int numAnts;
    double alpha;
    double betha;
    double evaporationRate;
    int distance;
};

#endif // TUNERDIALOG_H

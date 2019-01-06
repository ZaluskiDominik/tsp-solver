#ifndef TUNERDIALOG_H
#define TUNERDIALOG_H

#include <QDialog>
#include "ui_tunerdialog.h"
#include <QVector>
#include <QTimer>
#include <atomic>
#include <mutex>

class TunerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TunerDialog(QWidget *parent = nullptr);

private:
    //definitions of those structures are below TunerDialog class definition
    struct ParamRange;
    struct ParamsSet;
    struct ParamsSetResult;

    Ui::TunerDialog ui;

    //means of synchronizing access to results vector
    std::mutex mutex;

    //total number of runs of tsp solver program
    //it's a (number of possible parameters sets) * (number of runs for each set)
    int numTotalRuns;

    //number of times tsp solver was executed
    //it's modified by many threads, thus atomic is needed
    std::atomic<int> numAlreadyRun;

    //number of threads that are running processes of tsp solver
    //it's modified by many threads, thus atomic is needed
    std::atomic<int> numThreads;

    //timer counting time elapsed from start of running ant colony tsp solver with different parameters
    QTimer timer;

    //array of parameters ranges for tsp ant colony algorithm
    QVector<ParamRange> params;

    //vector with result of running ant colony for each generated parameters set
    QVector<ParamsSetResult> results;

    //append parameters to params array
    void initParamRanges();

    //disables/enables all gui components in general options group box
    //disabled when yes var is true
    void disableGeneralOptions(bool yes = true);

    //generates all possible parameters sets for solving tsp instance with ant colony algorithm
    void computeAllParamsSets();

    //calculates number of possible parameters sets that can be generated from params vector
    int calcNumPossibleSets();

    //computes next parameters set
    //returns false if all parameters sets were generated
    bool nextParamsSet();

    //runs ant colony algorithm with given parameters set
    void runInstance(ParamsSet set);

    //result of ran ant colony algorithm with given params is available
    void paramsSetResultAvailable(int distance, std::string& path);

    //tsp solver was ran with all generated parameters sets
    void allParamsExecuted();

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

    //update of value of progress bar was requested from another thread
    //updates progress of progress bar according to ratio numAlreadyRun / numTotalRuns
    void onUpdateProgressBar();

signals:
    void stopTimer();
    void updateProgressBar();
};

//structure representing range of values that a parameter can take
struct TunerDialog::ParamRange
{
    ParamRange() = default;
    ParamRange(double minVal, double maxVal, double step)
    {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->step = step;
        this->val = minVal;
    }

    double minVal, maxVal;
    double step;
    double val;
};

//structure representing set of parameters for ant colony cmd args
struct TunerDialog::ParamsSet
{
    int numAnts;
    double alpha;
    double betha;
    double evaporationRate;
};

//structure representing result of executing tsp solver ant colony
struct TunerDialog::ParamsSetResult
{
    ParamsSet set;
    int distance;
    std::string path;
};

#endif // TUNERDIALOG_H

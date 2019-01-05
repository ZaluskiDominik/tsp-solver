/********************************************************************************
** Form generated from reading UI file 'tunerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUNERDIALOG_H
#define UI_TUNERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TunerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *alphaStep;
    QLabel *label_8;
    QLabel *label_5;
    QDoubleSpinBox *alphaMin;
    QDoubleSpinBox *alphaMax;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox1;
    QGridLayout *gridLayout;
    QSpinBox *antsMax;
    QLabel *label;
    QSpinBox *antsMin;
    QLabel *label_2;
    QLabel *label_16;
    QSpinBox *antsStep;
    QGroupBox *groupBox2;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QSpinBox *timeLimit;
    QLineEdit *instanceFile;
    QPushButton *chooseInstBtn;
    QSpinBox *numRuns;
    QLineEdit *outFile;
    QPushButton *chooseOutFileBtn;
    QLabel *label_11;
    QLabel *label_17;
    QSpinBox *numThreads;
    QGroupBox *groupBox3;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *bethaMin;
    QDoubleSpinBox *bethaMax;
    QLabel *label_7;
    QDoubleSpinBox *bethaStep;
    QLabel *label_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpinBox *evapMin;
    QSpinBox *evapStep;
    QSpinBox *evapMax;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QProgressBar *progressBar;
    QLabel *label_10;
    QLabel *elapsedTime;
    QSpacerItem *horizontalSpacer;
    QPushButton *startBtn;

    void setupUi(QDialog *TunerDialog)
    {
        if (TunerDialog->objectName().isEmpty())
            TunerDialog->setObjectName(QStringLiteral("TunerDialog"));
        TunerDialog->resize(1209, 798);
        TunerDialog->setMinimumSize(QSize(1000, 750));
        verticalLayout = new QVBoxLayout(TunerDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox = new QGroupBox(TunerDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        alphaStep = new QDoubleSpinBox(groupBox);
        alphaStep->setObjectName(QStringLiteral("alphaStep"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(alphaStep->sizePolicy().hasHeightForWidth());
        alphaStep->setSizePolicy(sizePolicy);
        alphaStep->setMinimumSize(QSize(200, 40));
        alphaStep->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(14);
        alphaStep->setFont(font1);
        alphaStep->setMinimum(0.1);
        alphaStep->setMaximum(10);
        alphaStep->setSingleStep(0.1);

        gridLayout_2->addWidget(alphaStep, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(200, 40));
        label_8->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(200, 40));
        label_5->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        alphaMin = new QDoubleSpinBox(groupBox);
        alphaMin->setObjectName(QStringLiteral("alphaMin"));
        sizePolicy.setHeightForWidth(alphaMin->sizePolicy().hasHeightForWidth());
        alphaMin->setSizePolicy(sizePolicy);
        alphaMin->setMinimumSize(QSize(200, 40));
        alphaMin->setMaximumSize(QSize(300, 16777215));
        alphaMin->setFont(font1);
        alphaMin->setMinimum(1);
        alphaMin->setMaximum(100);
        alphaMin->setSingleStep(0.1);
        alphaMin->setValue(1);

        gridLayout_2->addWidget(alphaMin, 0, 1, 1, 1);

        alphaMax = new QDoubleSpinBox(groupBox);
        alphaMax->setObjectName(QStringLiteral("alphaMax"));
        sizePolicy.setHeightForWidth(alphaMax->sizePolicy().hasHeightForWidth());
        alphaMax->setSizePolicy(sizePolicy);
        alphaMax->setMinimumSize(QSize(200, 40));
        alphaMax->setMaximumSize(QSize(300, 16777215));
        alphaMax->setFont(font1);
        alphaMax->setMinimum(1);
        alphaMax->setMaximum(100);
        alphaMax->setSingleStep(0.1);
        alphaMax->setValue(1);

        gridLayout_2->addWidget(alphaMax, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(200, 40));
        label_4->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        groupBox1 = new QGroupBox(TunerDialog);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setFont(font);
        gridLayout = new QGridLayout(groupBox1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        antsMax = new QSpinBox(groupBox1);
        antsMax->setObjectName(QStringLiteral("antsMax"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(antsMax->sizePolicy().hasHeightForWidth());
        antsMax->setSizePolicy(sizePolicy2);
        antsMax->setMinimumSize(QSize(100, 40));
        antsMax->setFont(font1);
        antsMax->setMinimum(1);
        antsMax->setMaximum(200);
        antsMax->setSingleStep(1);
        antsMax->setValue(20);

        gridLayout->addWidget(antsMax, 1, 2, 1, 1);

        label = new QLabel(groupBox1);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(160, 40));
        label->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        antsMin = new QSpinBox(groupBox1);
        antsMin->setObjectName(QStringLiteral("antsMin"));
        sizePolicy2.setHeightForWidth(antsMin->sizePolicy().hasHeightForWidth());
        antsMin->setSizePolicy(sizePolicy2);
        antsMin->setMinimumSize(QSize(100, 40));
        antsMin->setFont(font1);
        antsMin->setMinimum(1);
        antsMin->setMaximum(200);
        antsMin->setSingleStep(1);
        antsMin->setValue(20);

        gridLayout->addWidget(antsMin, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox1);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(160, 40));
        label_2->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_16 = new QLabel(groupBox1);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setMinimumSize(QSize(0, 40));
        label_16->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout->addWidget(label_16, 2, 1, 1, 1);

        antsStep = new QSpinBox(groupBox1);
        antsStep->setObjectName(QStringLiteral("antsStep"));
        sizePolicy2.setHeightForWidth(antsStep->sizePolicy().hasHeightForWidth());
        antsStep->setSizePolicy(sizePolicy2);
        antsStep->setMinimumSize(QSize(0, 40));
        QFont font2;
        antsStep->setFont(font2);
        antsStep->setStyleSheet(QStringLiteral("font-size: 16px;"));
        antsStep->setMinimum(1);

        gridLayout->addWidget(antsStep, 2, 2, 1, 1);


        gridLayout_6->addWidget(groupBox1, 0, 2, 1, 1);

        groupBox2 = new QGroupBox(TunerDialog);
        groupBox2->setObjectName(QStringLiteral("groupBox2"));
        groupBox2->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(groupBox2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(290, 40));
        label_3->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        timeLimit = new QSpinBox(groupBox2);
        timeLimit->setObjectName(QStringLiteral("timeLimit"));
        sizePolicy1.setHeightForWidth(timeLimit->sizePolicy().hasHeightForWidth());
        timeLimit->setSizePolicy(sizePolicy1);
        timeLimit->setMinimumSize(QSize(100, 40));
        timeLimit->setFont(font1);
        timeLimit->setMinimum(1);
        timeLimit->setMaximum(999);
        timeLimit->setValue(10);

        gridLayout_4->addWidget(timeLimit, 2, 1, 1, 1);

        instanceFile = new QLineEdit(groupBox2);
        instanceFile->setObjectName(QStringLiteral("instanceFile"));
        instanceFile->setMinimumSize(QSize(0, 40));
        instanceFile->setFont(font1);
        instanceFile->setReadOnly(true);

        gridLayout_4->addWidget(instanceFile, 0, 1, 1, 1);

        chooseInstBtn = new QPushButton(groupBox2);
        chooseInstBtn->setObjectName(QStringLiteral("chooseInstBtn"));
        chooseInstBtn->setMinimumSize(QSize(0, 40));
        chooseInstBtn->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_4->addWidget(chooseInstBtn, 0, 0, 1, 1);

        numRuns = new QSpinBox(groupBox2);
        numRuns->setObjectName(QStringLiteral("numRuns"));
        sizePolicy1.setHeightForWidth(numRuns->sizePolicy().hasHeightForWidth());
        numRuns->setSizePolicy(sizePolicy1);
        numRuns->setMinimumSize(QSize(100, 40));
        numRuns->setFont(font1);
        numRuns->setMinimum(1);
        numRuns->setMaximum(1000);

        gridLayout_4->addWidget(numRuns, 3, 1, 1, 1);

        outFile = new QLineEdit(groupBox2);
        outFile->setObjectName(QStringLiteral("outFile"));
        outFile->setMinimumSize(QSize(0, 40));
        outFile->setFont(font1);
        outFile->setReadOnly(true);

        gridLayout_4->addWidget(outFile, 1, 1, 1, 1);

        chooseOutFileBtn = new QPushButton(groupBox2);
        chooseOutFileBtn->setObjectName(QStringLiteral("chooseOutFileBtn"));
        chooseOutFileBtn->setMinimumSize(QSize(0, 40));
        chooseOutFileBtn->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_4->addWidget(chooseOutFileBtn, 1, 0, 1, 1);

        label_11 = new QLabel(groupBox2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(290, 40));
        label_11->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        label_17 = new QLabel(groupBox2);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy3.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy3);
        label_17->setMinimumSize(QSize(290, 40));
        label_17->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_4->addWidget(label_17, 5, 0, 1, 1);

        numThreads = new QSpinBox(groupBox2);
        numThreads->setObjectName(QStringLiteral("numThreads"));
        sizePolicy1.setHeightForWidth(numThreads->sizePolicy().hasHeightForWidth());
        numThreads->setSizePolicy(sizePolicy1);
        numThreads->setMinimumSize(QSize(100, 40));
        numThreads->setFont(font1);
        numThreads->setMinimum(1);
        numThreads->setMaximum(10);

        gridLayout_4->addWidget(numThreads, 5, 1, 1, 1);


        gridLayout_6->addWidget(groupBox2, 0, 0, 1, 1);

        groupBox3 = new QGroupBox(TunerDialog);
        groupBox3->setObjectName(QStringLiteral("groupBox3"));
        groupBox3->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(groupBox3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(160, 40));
        label_6->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        bethaMin = new QDoubleSpinBox(groupBox3);
        bethaMin->setObjectName(QStringLiteral("bethaMin"));
        bethaMin->setMinimumSize(QSize(100, 40));
        bethaMin->setFont(font1);
        bethaMin->setMinimum(1);
        bethaMin->setMaximum(100);
        bethaMin->setSingleStep(0.1);
        bethaMin->setValue(2);

        gridLayout_3->addWidget(bethaMin, 0, 1, 1, 1);

        bethaMax = new QDoubleSpinBox(groupBox3);
        bethaMax->setObjectName(QStringLiteral("bethaMax"));
        bethaMax->setMinimumSize(QSize(100, 40));
        bethaMax->setFont(font1);
        bethaMax->setMinimum(1);
        bethaMax->setMaximum(100);
        bethaMax->setSingleStep(0.1);
        bethaMax->setValue(2);

        gridLayout_3->addWidget(bethaMax, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(160, 40));
        label_7->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        bethaStep = new QDoubleSpinBox(groupBox3);
        bethaStep->setObjectName(QStringLiteral("bethaStep"));
        bethaStep->setMinimumSize(QSize(100, 40));
        bethaStep->setFont(font1);
        bethaStep->setMinimum(0.1);
        bethaStep->setMaximum(10);
        bethaStep->setSingleStep(0.1);

        gridLayout_3->addWidget(bethaStep, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(160, 40));
        label_9->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);


        gridLayout_6->addWidget(groupBox3, 1, 2, 1, 1);

        groupBox_2 = new QGroupBox(TunerDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMinimumSize(QSize(200, 40));
        label_13->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_5->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(200, 40));
        label_14->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_5->addWidget(label_14, 1, 0, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(200, 40));
        label_15->setStyleSheet(QStringLiteral("font-size: 16px;"));

        gridLayout_5->addWidget(label_15, 0, 0, 1, 1);

        evapMin = new QSpinBox(groupBox_2);
        evapMin->setObjectName(QStringLiteral("evapMin"));
        sizePolicy.setHeightForWidth(evapMin->sizePolicy().hasHeightForWidth());
        evapMin->setSizePolicy(sizePolicy);
        evapMin->setMinimumSize(QSize(200, 40));
        evapMin->setMaximumSize(QSize(300, 16777215));
        evapMin->setFont(font1);
        evapMin->setMaximum(100);
        evapMin->setValue(50);

        gridLayout_5->addWidget(evapMin, 0, 1, 1, 1);

        evapStep = new QSpinBox(groupBox_2);
        evapStep->setObjectName(QStringLiteral("evapStep"));
        sizePolicy.setHeightForWidth(evapStep->sizePolicy().hasHeightForWidth());
        evapStep->setSizePolicy(sizePolicy);
        evapStep->setMinimumSize(QSize(200, 40));
        evapStep->setMaximumSize(QSize(300, 16777215));
        evapStep->setFont(font1);
        evapStep->setMinimum(1);

        gridLayout_5->addWidget(evapStep, 2, 1, 1, 1);

        evapMax = new QSpinBox(groupBox_2);
        evapMax->setObjectName(QStringLiteral("evapMax"));
        sizePolicy.setHeightForWidth(evapMax->sizePolicy().hasHeightForWidth());
        evapMax->setSizePolicy(sizePolicy);
        evapMax->setMinimumSize(QSize(200, 40));
        evapMax->setMaximumSize(QSize(300, 16777215));
        evapMax->setFont(font1);
        evapMax->setMaximum(100);
        evapMax->setValue(50);

        gridLayout_5->addWidget(evapMax, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_12 = new QLabel(TunerDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setMinimumSize(QSize(80, 0));
        label_12->setStyleSheet(QStringLiteral("font-size: 17px;"));

        horizontalLayout->addWidget(label_12);

        progressBar = new QProgressBar(TunerDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(0, 30));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        label_10 = new QLabel(TunerDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setStyleSheet(QStringLiteral("font-size: 19px;"));

        horizontalLayout->addWidget(label_10);

        elapsedTime = new QLabel(TunerDialog);
        elapsedTime->setObjectName(QStringLiteral("elapsedTime"));
        sizePolicy3.setHeightForWidth(elapsedTime->sizePolicy().hasHeightForWidth());
        elapsedTime->setSizePolicy(sizePolicy3);
        elapsedTime->setMinimumSize(QSize(100, 0));
        elapsedTime->setStyleSheet(QLatin1String("font-size: 19px;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(elapsedTime);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        startBtn = new QPushButton(TunerDialog);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        sizePolicy1.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy1);
        startBtn->setMinimumSize(QSize(160, 40));
        startBtn->setStyleSheet(QStringLiteral("font-size: 22px;"));

        verticalLayout->addWidget(startBtn, 0, Qt::AlignHCenter);


        retranslateUi(TunerDialog);

        QMetaObject::connectSlotsByName(TunerDialog);
    } // setupUi

    void retranslateUi(QDialog *TunerDialog)
    {
        TunerDialog->setWindowTitle(QApplication::translate("TunerDialog", "Ant Colony Tuner", nullptr));
        groupBox->setTitle(QApplication::translate("TunerDialog", "Alpha", nullptr));
        label_8->setText(QApplication::translate("TunerDialog", "Step:", nullptr));
        label_5->setText(QApplication::translate("TunerDialog", "Maximal value:", nullptr));
        label_4->setText(QApplication::translate("TunerDialog", "Minimal value:", nullptr));
        groupBox1->setTitle(QApplication::translate("TunerDialog", "Number of ants", nullptr));
        label->setText(QApplication::translate("TunerDialog", "Minimal value:", nullptr));
        label_2->setText(QApplication::translate("TunerDialog", "Maximal value:", nullptr));
        label_16->setText(QApplication::translate("TunerDialog", "Step:", nullptr));
        groupBox2->setTitle(QApplication::translate("TunerDialog", "General options", nullptr));
        label_3->setText(QApplication::translate("TunerDialog", "Number of seconds for one execution:", nullptr));
        chooseInstBtn->setText(QApplication::translate("TunerDialog", "Choose instance", nullptr));
        chooseOutFileBtn->setText(QApplication::translate("TunerDialog", "Choose output file", nullptr));
        label_11->setText(QApplication::translate("TunerDialog", "Number of runs of one parameters set:", nullptr));
        label_17->setText(QApplication::translate("TunerDialog", "Number of threads:", nullptr));
        groupBox3->setTitle(QApplication::translate("TunerDialog", "Betha", nullptr));
        label_6->setText(QApplication::translate("TunerDialog", "Maximal value:", nullptr));
        label_7->setText(QApplication::translate("TunerDialog", "Minimal value:", nullptr));
        label_9->setText(QApplication::translate("TunerDialog", "Step:", nullptr));
        groupBox_2->setTitle(QApplication::translate("TunerDialog", "Pheromones evaporation rate", nullptr));
        label_13->setText(QApplication::translate("TunerDialog", "Step[%]:", nullptr));
        label_14->setText(QApplication::translate("TunerDialog", "Maximal value[%]:", nullptr));
        label_15->setText(QApplication::translate("TunerDialog", "Minimal value[%]:", nullptr));
        label_12->setText(QApplication::translate("TunerDialog", "Progress:", nullptr));
        label_10->setText(QApplication::translate("TunerDialog", "Elapsed time[s]:", nullptr));
        elapsedTime->setText(QApplication::translate("TunerDialog", "0", nullptr));
        startBtn->setText(QApplication::translate("TunerDialog", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TunerDialog: public Ui_TunerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUNERDIALOG_H

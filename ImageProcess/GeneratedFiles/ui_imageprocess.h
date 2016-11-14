/********************************************************************************
** Form generated from reading UI file 'imageprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESS_H
#define UI_IMAGEPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSave_as;
    QAction *actionReverse;
    QAction *actionRotate_CW;
    QAction *actionRotate_CCW;
    QAction *actionChoose_Clip_Area;
    QAction *actionClip;
    QAction *actionExit_Choose;
    QWidget *centralWidget;
    QLabel *imageLabel;
    QTabWidget *tabWidget;
    QWidget *hue;
    QSlider *hueSlider;
    QLabel *hueLabel;
    QPushButton *hueButton;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *hueInput;
    QWidget *saturation;
    QLabel *satLabel;
    QPushButton *satButton;
    QSlider *satSlider;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *satInput;
    QWidget *intensity;
    QSlider *intSlider;
    QPushButton *intButton;
    QLabel *intLabel;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *intInput;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageProcessClass)
    {
        if (ImageProcessClass->objectName().isEmpty())
            ImageProcessClass->setObjectName(QStringLiteral("ImageProcessClass"));
        ImageProcessClass->resize(600, 400);
        actionOpen = new QAction(ImageProcessClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(ImageProcessClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionExit = new QAction(ImageProcessClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave_as = new QAction(ImageProcessClass);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_as->setEnabled(false);
        actionReverse = new QAction(ImageProcessClass);
        actionReverse->setObjectName(QStringLiteral("actionReverse"));
        actionReverse->setEnabled(false);
        actionRotate_CW = new QAction(ImageProcessClass);
        actionRotate_CW->setObjectName(QStringLiteral("actionRotate_CW"));
        actionRotate_CW->setEnabled(false);
        actionRotate_CCW = new QAction(ImageProcessClass);
        actionRotate_CCW->setObjectName(QStringLiteral("actionRotate_CCW"));
        actionRotate_CCW->setEnabled(false);
        actionChoose_Clip_Area = new QAction(ImageProcessClass);
        actionChoose_Clip_Area->setObjectName(QStringLiteral("actionChoose_Clip_Area"));
        actionChoose_Clip_Area->setEnabled(false);
        actionClip = new QAction(ImageProcessClass);
        actionClip->setObjectName(QStringLiteral("actionClip"));
        actionClip->setEnabled(false);
        actionExit_Choose = new QAction(ImageProcessClass);
        actionExit_Choose->setObjectName(QStringLiteral("actionExit_Choose"));
        actionExit_Choose->setEnabled(false);
        centralWidget = new QWidget(ImageProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(0, 60, 471, 291));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(false);
        tabWidget->setGeometry(QRect(0, 0, 600, 61));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        hue = new QWidget();
        hue->setObjectName(QStringLiteral("hue"));
        hueSlider = new QSlider(hue);
        hueSlider->setObjectName(QStringLiteral("hueSlider"));
        hueSlider->setGeometry(QRect(360, 8, 160, 22));
        hueSlider->setMaximum(360);
        hueSlider->setOrientation(Qt::Horizontal);
        hueLabel = new QLabel(hue);
        hueLabel->setObjectName(QStringLiteral("hueLabel"));
        hueLabel->setGeometry(QRect(10, 13, 54, 12));
        hueButton = new QPushButton(hue);
        hueButton->setObjectName(QStringLiteral("hueButton"));
        hueButton->setGeometry(QRect(210, 8, 75, 22));
        label = new QLabel(hue);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 10, 21, 16));
        label_2 = new QLabel(hue);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 10, 31, 16));
        hueInput = new QDoubleSpinBox(hue);
        hueInput->setObjectName(QStringLiteral("hueInput"));
        hueInput->setGeometry(QRect(80, 9, 113, 20));
        hueInput->setMaximum(360);
        tabWidget->addTab(hue, QString());
        saturation = new QWidget();
        saturation->setObjectName(QStringLiteral("saturation"));
        satLabel = new QLabel(saturation);
        satLabel->setObjectName(QStringLiteral("satLabel"));
        satLabel->setGeometry(QRect(10, 13, 54, 12));
        satButton = new QPushButton(saturation);
        satButton->setObjectName(QStringLiteral("satButton"));
        satButton->setGeometry(QRect(210, 8, 75, 22));
        satSlider = new QSlider(saturation);
        satSlider->setObjectName(QStringLiteral("satSlider"));
        satSlider->setGeometry(QRect(360, 8, 160, 22));
        satSlider->setMinimum(-100);
        satSlider->setMaximum(100);
        satSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(saturation);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(325, 9, 31, 20));
        label_4 = new QLabel(saturation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(530, 9, 21, 20));
        satInput = new QDoubleSpinBox(saturation);
        satInput->setObjectName(QStringLiteral("satInput"));
        satInput->setGeometry(QRect(80, 9, 113, 20));
        satInput->setMinimum(-100);
        satInput->setMaximum(100);
        satInput->setSingleStep(1);
        tabWidget->addTab(saturation, QString());
        intensity = new QWidget();
        intensity->setObjectName(QStringLiteral("intensity"));
        intSlider = new QSlider(intensity);
        intSlider->setObjectName(QStringLiteral("intSlider"));
        intSlider->setGeometry(QRect(360, 8, 160, 22));
        intSlider->setMinimum(-100);
        intSlider->setMaximum(100);
        intSlider->setOrientation(Qt::Horizontal);
        intButton = new QPushButton(intensity);
        intButton->setObjectName(QStringLiteral("intButton"));
        intButton->setGeometry(QRect(210, 8, 75, 22));
        intLabel = new QLabel(intensity);
        intLabel->setObjectName(QStringLiteral("intLabel"));
        intLabel->setGeometry(QRect(10, 13, 54, 12));
        label_5 = new QLabel(intensity);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(325, 9, 31, 20));
        label_6 = new QLabel(intensity);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(530, 9, 21, 20));
        intInput = new QDoubleSpinBox(intensity);
        intInput->setObjectName(QStringLiteral("intInput"));
        intInput->setGeometry(QRect(80, 9, 113, 20));
        intInput->setMinimum(-100);
        intInput->setMaximum(100);
        intInput->setSingleStep(1);
        tabWidget->addTab(intensity, QString());
        ImageProcessClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageProcessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuBar->setContextMenuPolicy(Qt::NoContextMenu);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        ImageProcessClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ImageProcessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageProcessClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionReverse);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRotate_CW);
        menuEdit->addAction(actionRotate_CCW);
        menuEdit->addSeparator();
        menuEdit->addAction(actionChoose_Clip_Area);
        menuEdit->addAction(actionExit_Choose);
        menuEdit->addAction(actionClip);

        retranslateUi(ImageProcessClass);
        QObject::connect(actionExit, SIGNAL(triggered()), ImageProcessClass, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImageProcessClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageProcessClass)
    {
        ImageProcessClass->setWindowTitle(QApplication::translate("ImageProcessClass", "ImageProcess", 0));
        actionOpen->setText(QApplication::translate("ImageProcessClass", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("ImageProcessClass", "Open exist file", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("ImageProcessClass", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("ImageProcessClass", "Save the file", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("ImageProcessClass", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("ImageProcessClass", "Exit the program", 0));
#endif // QT_NO_TOOLTIP
        actionSave_as->setText(QApplication::translate("ImageProcessClass", "Save as..", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_as->setToolTip(QApplication::translate("ImageProcessClass", "Save the file as...", 0));
#endif // QT_NO_TOOLTIP
        actionReverse->setText(QApplication::translate("ImageProcessClass", "Reverse", 0));
#ifndef QT_NO_TOOLTIP
        actionReverse->setToolTip(QApplication::translate("ImageProcessClass", "Reverse the image", 0));
#endif // QT_NO_TOOLTIP
        actionRotate_CW->setText(QApplication::translate("ImageProcessClass", "Rotate CW", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate_CW->setToolTip(QApplication::translate("ImageProcessClass", "Rotate 90 degree clockwise", 0));
#endif // QT_NO_TOOLTIP
        actionRotate_CCW->setText(QApplication::translate("ImageProcessClass", "Rotate CCW", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate_CCW->setToolTip(QApplication::translate("ImageProcessClass", "Rotate 90 degree counter clockwise", 0));
#endif // QT_NO_TOOLTIP
        actionChoose_Clip_Area->setText(QApplication::translate("ImageProcessClass", "Choose Clip Area", 0));
#ifndef QT_NO_TOOLTIP
        actionChoose_Clip_Area->setToolTip(QApplication::translate("ImageProcessClass", "Choose the clip area", 0));
#endif // QT_NO_TOOLTIP
        actionClip->setText(QApplication::translate("ImageProcessClass", "Clip", 0));
#ifndef QT_NO_TOOLTIP
        actionClip->setToolTip(QApplication::translate("ImageProcessClass", "Clip the image with the chosen area", 0));
#endif // QT_NO_TOOLTIP
        actionExit_Choose->setText(QApplication::translate("ImageProcessClass", "Exit Choose", 0));
#ifndef QT_NO_TOOLTIP
        actionExit_Choose->setToolTip(QApplication::translate("ImageProcessClass", "Exit choosing clip area mode", 0));
#endif // QT_NO_TOOLTIP
        imageLabel->setText(QString());
        hueLabel->setText(QApplication::translate("ImageProcessClass", "Input:", 0));
        hueButton->setText(QApplication::translate("ImageProcessClass", "Adjust", 0));
        label->setText(QApplication::translate("ImageProcessClass", "0\302\260", 0));
        label_2->setText(QApplication::translate("ImageProcessClass", "360\302\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(hue), QApplication::translate("ImageProcessClass", "Hue", 0));
        satLabel->setText(QApplication::translate("ImageProcessClass", "Input:", 0));
        satButton->setText(QApplication::translate("ImageProcessClass", "Adjust", 0));
        label_3->setText(QApplication::translate("ImageProcessClass", "-100", 0));
        label_4->setText(QApplication::translate("ImageProcessClass", "100", 0));
        tabWidget->setTabText(tabWidget->indexOf(saturation), QApplication::translate("ImageProcessClass", "Saturation", 0));
        intButton->setText(QApplication::translate("ImageProcessClass", "Adjust", 0));
        intLabel->setText(QApplication::translate("ImageProcessClass", "Input:", 0));
        label_5->setText(QApplication::translate("ImageProcessClass", "-100", 0));
        label_6->setText(QApplication::translate("ImageProcessClass", "100", 0));
        tabWidget->setTabText(tabWidget->indexOf(intensity), QApplication::translate("ImageProcessClass", "Intensity", 0));
        menuFile->setTitle(QApplication::translate("ImageProcessClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("ImageProcessClass", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageProcessClass: public Ui_ImageProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H

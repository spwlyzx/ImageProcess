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
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QTextBrowser>
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
    QAction *actionHistogram_Equalization;
    QAction *actionChoose_a_image_SML;
    QAction *actionNormal_Distribution_SML;
    QAction *actionChoose_a_image_GML;
    QAction *actionGaussian_Blur;
    QAction *actionImage_Sharpening;
    QAction *action3_3;
    QAction *action5_5_template;
    QAction *action7_7template;
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
    QWidget *Linear;
    QLabel *label_7;
    QDoubleSpinBox *Linear_x;
    QLabel *label_8;
    QDoubleSpinBox *Linear_y;
    QPushButton *Linear_add;
    QTextBrowser *Linear_points;
    QPushButton *Linear_apply;
    QLabel *label_9;
    QWidget *GreyOther;
    QComboBox *GreyMethods;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *Grey_a;
    QDoubleSpinBox *Grey_b;
    QDoubleSpinBox *Grey_c;
    QLabel *label_13;
    QDoubleSpinBox *Grey_gamma;
    QPushButton *Grey_apply;
    QWidget *SpatialFiltering;
    QComboBox *SpatialType;
    QSlider *SpatialTemplateSize;
    QLabel *label_14;
    QLabel *SpatialSizeLabel;
    QPushButton *ImageSharpening;
    QComboBox *ImageSharpeningFactor;
    QPushButton *SpatialApply;
    QWidget *tab;
    QComboBox *FrequencyFilterType;
    QSlider *FrequencyD0;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *FrequencyApply;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHistogram_Specification;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageProcessClass)
    {
        if (ImageProcessClass->objectName().isEmpty())
            ImageProcessClass->setObjectName(QStringLiteral("ImageProcessClass"));
        ImageProcessClass->resize(800, 600);
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
        actionHistogram_Equalization = new QAction(ImageProcessClass);
        actionHistogram_Equalization->setObjectName(QStringLiteral("actionHistogram_Equalization"));
        actionHistogram_Equalization->setEnabled(false);
        actionChoose_a_image_SML = new QAction(ImageProcessClass);
        actionChoose_a_image_SML->setObjectName(QStringLiteral("actionChoose_a_image_SML"));
        actionChoose_a_image_SML->setEnabled(false);
        actionNormal_Distribution_SML = new QAction(ImageProcessClass);
        actionNormal_Distribution_SML->setObjectName(QStringLiteral("actionNormal_Distribution_SML"));
        actionNormal_Distribution_SML->setEnabled(false);
        actionChoose_a_image_GML = new QAction(ImageProcessClass);
        actionChoose_a_image_GML->setObjectName(QStringLiteral("actionChoose_a_image_GML"));
        actionChoose_a_image_GML->setEnabled(false);
        actionGaussian_Blur = new QAction(ImageProcessClass);
        actionGaussian_Blur->setObjectName(QStringLiteral("actionGaussian_Blur"));
        actionGaussian_Blur->setEnabled(false);
        actionImage_Sharpening = new QAction(ImageProcessClass);
        actionImage_Sharpening->setObjectName(QStringLiteral("actionImage_Sharpening"));
        actionImage_Sharpening->setEnabled(false);
        action3_3 = new QAction(ImageProcessClass);
        action3_3->setObjectName(QStringLiteral("action3_3"));
        action5_5_template = new QAction(ImageProcessClass);
        action5_5_template->setObjectName(QStringLiteral("action5_5_template"));
        action7_7template = new QAction(ImageProcessClass);
        action7_7template->setObjectName(QStringLiteral("action7_7template"));
        centralWidget = new QWidget(ImageProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(0, 60, 761, 451));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(false);
        tabWidget->setGeometry(QRect(0, 0, 800, 61));
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
        Linear = new QWidget();
        Linear->setObjectName(QStringLiteral("Linear"));
        label_7 = new QLabel(Linear);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 51, 16));
        Linear_x = new QDoubleSpinBox(Linear);
        Linear_x->setObjectName(QStringLiteral("Linear_x"));
        Linear_x->setGeometry(QRect(60, 8, 51, 22));
        Linear_x->setMaximum(255);
        label_8 = new QLabel(Linear);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(122, 10, 21, 16));
        Linear_y = new QDoubleSpinBox(Linear);
        Linear_y->setObjectName(QStringLiteral("Linear_y"));
        Linear_y->setGeometry(QRect(136, 8, 51, 22));
        Linear_y->setMaximum(255);
        Linear_add = new QPushButton(Linear);
        Linear_add->setObjectName(QStringLiteral("Linear_add"));
        Linear_add->setGeometry(QRect(210, 8, 51, 23));
        Linear_points = new QTextBrowser(Linear);
        Linear_points->setObjectName(QStringLiteral("Linear_points"));
        Linear_points->setGeometry(QRect(360, 9, 151, 21));
        Linear_apply = new QPushButton(Linear);
        Linear_apply->setObjectName(QStringLiteral("Linear_apply"));
        Linear_apply->setGeometry(QRect(520, 8, 66, 23));
        label_9 = new QLabel(Linear);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(315, 10, 54, 16));
        tabWidget->addTab(Linear, QString());
        GreyOther = new QWidget();
        GreyOther->setObjectName(QStringLiteral("GreyOther"));
        GreyMethods = new QComboBox(GreyOther);
        GreyMethods->setObjectName(QStringLiteral("GreyMethods"));
        GreyMethods->setGeometry(QRect(10, 8, 131, 22));
        GreyMethods->setMaxCount(2147483646);
        label_10 = new QLabel(GreyOther);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(155, 11, 16, 16));
        label_11 = new QLabel(GreyOther);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(244, 12, 16, 16));
        label_12 = new QLabel(GreyOther);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(336, 11, 16, 16));
        Grey_a = new QDoubleSpinBox(GreyOther);
        Grey_a->setObjectName(QStringLiteral("Grey_a"));
        Grey_a->setGeometry(QRect(168, 9, 61, 21));
        Grey_a->setDecimals(5);
        Grey_b = new QDoubleSpinBox(GreyOther);
        Grey_b->setObjectName(QStringLiteral("Grey_b"));
        Grey_b->setGeometry(QRect(259, 9, 61, 21));
        Grey_b->setDecimals(5);
        Grey_c = new QDoubleSpinBox(GreyOther);
        Grey_c->setObjectName(QStringLiteral("Grey_c"));
        Grey_c->setGeometry(QRect(351, 9, 61, 21));
        Grey_c->setDecimals(5);
        label_13 = new QLabel(GreyOther);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(445, 12, 41, 16));
        Grey_gamma = new QDoubleSpinBox(GreyOther);
        Grey_gamma->setObjectName(QStringLiteral("Grey_gamma"));
        Grey_gamma->setGeometry(QRect(487, 9, 62, 21));
        Grey_apply = new QPushButton(GreyOther);
        Grey_apply->setObjectName(QStringLiteral("Grey_apply"));
        Grey_apply->setGeometry(QRect(562, 9, 75, 23));
        tabWidget->addTab(GreyOther, QString());
        SpatialFiltering = new QWidget();
        SpatialFiltering->setObjectName(QStringLiteral("SpatialFiltering"));
        SpatialType = new QComboBox(SpatialFiltering);
        SpatialType->setObjectName(QStringLiteral("SpatialType"));
        SpatialType->setGeometry(QRect(10, 8, 141, 22));
        SpatialTemplateSize = new QSlider(SpatialFiltering);
        SpatialTemplateSize->setObjectName(QStringLiteral("SpatialTemplateSize"));
        SpatialTemplateSize->setGeometry(QRect(289, 10, 91, 22));
        SpatialTemplateSize->setMinimum(3);
        SpatialTemplateSize->setMaximum(27);
        SpatialTemplateSize->setSingleStep(2);
        SpatialTemplateSize->setPageStep(3);
        SpatialTemplateSize->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(SpatialFiltering);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(168, 11, 91, 16));
        SpatialSizeLabel = new QLabel(SpatialFiltering);
        SpatialSizeLabel->setObjectName(QStringLiteral("SpatialSizeLabel"));
        SpatialSizeLabel->setGeometry(QRect(273, 12, 12, 16));
        ImageSharpening = new QPushButton(SpatialFiltering);
        ImageSharpening->setObjectName(QStringLiteral("ImageSharpening"));
        ImageSharpening->setGeometry(QRect(654, 8, 131, 23));
        ImageSharpeningFactor = new QComboBox(SpatialFiltering);
        ImageSharpeningFactor->setObjectName(QStringLiteral("ImageSharpeningFactor"));
        ImageSharpeningFactor->setGeometry(QRect(568, 8, 71, 22));
        SpatialApply = new QPushButton(SpatialFiltering);
        SpatialApply->setObjectName(QStringLiteral("SpatialApply"));
        SpatialApply->setGeometry(QRect(391, 8, 75, 23));
        tabWidget->addTab(SpatialFiltering, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        FrequencyFilterType = new QComboBox(tab);
        FrequencyFilterType->setObjectName(QStringLiteral("FrequencyFilterType"));
        FrequencyFilterType->setGeometry(QRect(10, 8, 181, 22));
        FrequencyD0 = new QSlider(tab);
        FrequencyD0->setObjectName(QStringLiteral("FrequencyD0"));
        FrequencyD0->setGeometry(QRect(250, 10, 201, 22));
        FrequencyD0->setMinimum(5);
        FrequencyD0->setMaximum(1000);
        FrequencyD0->setValue(7);
        FrequencyD0->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(236, 11, 16, 16));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(464, 11, 21, 16));
        FrequencyApply = new QPushButton(tab);
        FrequencyApply->setObjectName(QStringLiteral("FrequencyApply"));
        FrequencyApply->setGeometry(QRect(518, 8, 75, 23));
        tabWidget->addTab(tab, QString());
        ImageProcessClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageProcessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuBar->setContextMenuPolicy(Qt::NoContextMenu);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHistogram_Specification = new QMenu(menuEdit);
        menuHistogram_Specification->setObjectName(QStringLiteral("menuHistogram_Specification"));
        menuHistogram_Specification->setEnabled(true);
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
        menuEdit->addSeparator();
        menuEdit->addAction(actionHistogram_Equalization);
        menuEdit->addAction(menuHistogram_Specification->menuAction());
        menuHistogram_Specification->addAction(actionChoose_a_image_SML);
        menuHistogram_Specification->addAction(actionChoose_a_image_GML);

        retranslateUi(ImageProcessClass);
        QObject::connect(actionExit, SIGNAL(triggered()), ImageProcessClass, SLOT(close()));

        tabWidget->setCurrentIndex(6);


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
        actionHistogram_Equalization->setText(QApplication::translate("ImageProcessClass", "Histogram Equalization", 0));
        actionChoose_a_image_SML->setText(QApplication::translate("ImageProcessClass", "Choose a image SML", 0));
        actionNormal_Distribution_SML->setText(QApplication::translate("ImageProcessClass", "Normal Distribution SML", 0));
        actionChoose_a_image_GML->setText(QApplication::translate("ImageProcessClass", "Choose a image GML", 0));
        actionGaussian_Blur->setText(QApplication::translate("ImageProcessClass", "Gaussian Blur", 0));
        actionImage_Sharpening->setText(QApplication::translate("ImageProcessClass", "Image Sharpening", 0));
        action3_3->setText(QApplication::translate("ImageProcessClass", "3*3 template", 0));
        action5_5_template->setText(QApplication::translate("ImageProcessClass", "5*5 template", 0));
        action7_7template->setText(QApplication::translate("ImageProcessClass", "7*7template", 0));
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
        label_7->setText(QApplication::translate("ImageProcessClass", "Point x:", 0));
        label_8->setText(QApplication::translate("ImageProcessClass", "y:", 0));
        Linear_add->setText(QApplication::translate("ImageProcessClass", "Add", 0));
        Linear_apply->setText(QApplication::translate("ImageProcessClass", "Apply", 0));
        label_9->setText(QApplication::translate("ImageProcessClass", "Points:", 0));
        tabWidget->setTabText(tabWidget->indexOf(Linear), QApplication::translate("ImageProcessClass", "GreyScale_Linear", 0));
        GreyMethods->clear();
        GreyMethods->insertItems(0, QStringList()
         << QApplication::translate("ImageProcessClass", "Log-transformation", 0)
         << QApplication::translate("ImageProcessClass", "Exp-transformation", 0)
         << QApplication::translate("ImageProcessClass", "Gamma Correction", 0)
        );
        GreyMethods->setCurrentText(QApplication::translate("ImageProcessClass", "Log-transformation", 0));
        label_10->setText(QApplication::translate("ImageProcessClass", "a", 0));
        label_11->setText(QApplication::translate("ImageProcessClass", "b", 0));
        label_12->setText(QApplication::translate("ImageProcessClass", "c", 0));
        label_13->setText(QApplication::translate("ImageProcessClass", "Gamma", 0));
        Grey_apply->setText(QApplication::translate("ImageProcessClass", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(GreyOther), QApplication::translate("ImageProcessClass", "GreyScale_Other", 0));
        SpatialType->clear();
        SpatialType->insertItems(0, QStringList()
         << QApplication::translate("ImageProcessClass", "Median Filter", 0)
         << QApplication::translate("ImageProcessClass", "Gaussian Blur", 0)
        );
        label_14->setText(QApplication::translate("ImageProcessClass", "Template Size:", 0));
        SpatialSizeLabel->setText(QApplication::translate("ImageProcessClass", "3", 0));
        ImageSharpening->setText(QApplication::translate("ImageProcessClass", "Image Sharpening", 0));
        ImageSharpeningFactor->clear();
        ImageSharpeningFactor->insertItems(0, QStringList()
         << QApplication::translate("ImageProcessClass", "Roberts", 0)
         << QApplication::translate("ImageProcessClass", "Prewitt", 0)
         << QApplication::translate("ImageProcessClass", "Sobel", 0)
        );
        SpatialApply->setText(QApplication::translate("ImageProcessClass", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(SpatialFiltering), QApplication::translate("ImageProcessClass", "Spatial Filtering ", 0));
        FrequencyFilterType->clear();
        FrequencyFilterType->insertItems(0, QStringList()
         << QApplication::translate("ImageProcessClass", "Gaussian Low Pass Filter", 0)
         << QApplication::translate("ImageProcessClass", "Gaussian High Pass Filter", 0)
        );
        label_15->setText(QApplication::translate("ImageProcessClass", "5", 0));
        label_16->setText(QApplication::translate("ImageProcessClass", "100", 0));
        FrequencyApply->setText(QApplication::translate("ImageProcessClass", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ImageProcessClass", "Frequency Filtering", 0));
        menuFile->setTitle(QApplication::translate("ImageProcessClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("ImageProcessClass", "Edit", 0));
        menuHistogram_Specification->setTitle(QApplication::translate("ImageProcessClass", "Histogram Specification", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageProcessClass: public Ui_ImageProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H

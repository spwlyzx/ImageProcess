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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QWidget *centralWidget;
    QLabel *imageLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
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
        actionExit = new QAction(ImageProcessClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave_as = new QAction(ImageProcessClass);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionReverse = new QAction(ImageProcessClass);
        actionReverse->setObjectName(QStringLiteral("actionReverse"));
        actionRotate_CW = new QAction(ImageProcessClass);
        actionRotate_CW->setObjectName(QStringLiteral("actionRotate_CW"));
        actionRotate_CCW = new QAction(ImageProcessClass);
        actionRotate_CCW->setObjectName(QStringLiteral("actionRotate_CCW"));
        centralWidget = new QWidget(ImageProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 121, 111));
        ImageProcessClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageProcessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        ImageProcessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageProcessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageProcessClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        menuEdit->addAction(actionRotate_CW);
        menuEdit->addAction(actionRotate_CCW);

        retranslateUi(ImageProcessClass);
        QObject::connect(actionExit, SIGNAL(triggered()), ImageProcessClass, SLOT(close()));

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
        imageLabel->setText(QString());
        menuFile->setTitle(QApplication::translate("ImageProcessClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("ImageProcessClass", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageProcessClass: public Ui_ImageProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageProcessClass)
    {
        if (ImageProcessClass->objectName().isEmpty())
            ImageProcessClass->setObjectName(QStringLiteral("ImageProcessClass"));
        ImageProcessClass->resize(600, 400);
        menuBar = new QMenuBar(ImageProcessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ImageProcessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageProcessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageProcessClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ImageProcessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageProcessClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImageProcessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageProcessClass->setStatusBar(statusBar);

        retranslateUi(ImageProcessClass);

        QMetaObject::connectSlotsByName(ImageProcessClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageProcessClass)
    {
        ImageProcessClass->setWindowTitle(QApplication::translate("ImageProcessClass", "ImageProcess", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageProcessClass: public Ui_ImageProcessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H

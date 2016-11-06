#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtWidgets/QMainWindow>
#include "ui_imageprocess.h"

class ImageProcess : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcess(QWidget *parent = 0);
	~ImageProcess();

private:
	Ui::ImageProcessClass ui;
};

#endif // IMAGEPROCESS_H

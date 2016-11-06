#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtWidgets/QMainWindow>
#include "ui_imageprocess.h"
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QFileDialog>

class ImageProcess : public QMainWindow
{
	Q_OBJECT
	cv::Mat image;

public:
	ImageProcess(QWidget *parent = 0);
	~ImageProcess();

public slots:
void fileOpenSlot();

private:
	void displayMat(cv::Mat img);

private:
	Ui::ImageProcessClass ui;
};

#endif // IMAGEPROCESS_H

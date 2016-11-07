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

private:
	Ui::ImageProcessClass ui;
	cv::Mat image;
	QString filename;

public:
	ImageProcess(QWidget *parent = 0);
	~ImageProcess();

public slots:
	void fileOpenSlot();
	void fileSaveSlot();
	void fileSaveAsSlot();

private:
	void displayMat(cv::Mat img);
};

#endif // IMAGEPROCESS_H

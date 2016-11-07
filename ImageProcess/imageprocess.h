#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtWidgets/QMainWindow>
#include "ui_imageprocess.h"
#include <QtWidgets/QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets/QFileDialog>
#include <QtGui/QMouseEvent> 
#include <QtWidgets/QRubberBand> 

class ImageProcess : public QMainWindow
{
	Q_OBJECT

	void ImageProcess::mousePressEvent(QMouseEvent *event);
	void ImageProcess::mouseMoveEvent(QMouseEvent *event);
	void ImageProcess::mouseReleaseEvent(QMouseEvent *event);

private:
	Ui::ImageProcessClass ui;
	cv::Mat image;
	QString filename;
	QRubberBand *rubberBand;
	QPoint origin;
	QPoint end;
	bool isClipping = false;

public:
	ImageProcess(QWidget *parent = 0);
	~ImageProcess();

private slots:
	void fileOpenSlot();
	void fileSaveSlot();
	void fileSaveAsSlot();
	void editReverseSlot();
	void editRotateCWSlot();
	void editRotateCCWSlot();
	void editChooseAreaSlot();
	void editClipSlot();
	void editExitClipSlot();

private:
	void displayMat(cv::Mat img);
	void assertNoFile();
	void limit(QPoint &x);
};

#endif // IMAGEPROCESS_H

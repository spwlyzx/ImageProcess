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
	cv::Mat originImage;
	QString filename;
	QRubberBand *rubberBand;
	QPoint origin;
	QPoint end;
	QSize imageSize;
	bool isClipping = false;
	bool isProcessing = false;

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
	void changeIntensitySlot(int change);
	void changeIntensityButtonSlot();
	void changeSaturationSlot(int change);
	void changeSaturationButtonSlot();
	void changeHueSlot(int change);
	void changeHueButtonSlot();

private:
	void displayMat(cv::Mat img);
	void assertNoFile();
	void limit(QPoint &x);
	void resizeMain();
	void changeIntensity(int change);
	void changeSaturation(int change);
	void changeHue(int change);
	int max(int a, int b, int c);
	int min(int a, int b, int c);
	void HsvToRgb(unsigned char &r, unsigned char &g, unsigned char &b, unsigned char h, unsigned char s, unsigned char v);
	void RgbToHsv(unsigned char r, unsigned char g, unsigned char b, unsigned char &h, unsigned char &s, unsigned char &v);

};

#endif // IMAGEPROCESS_H

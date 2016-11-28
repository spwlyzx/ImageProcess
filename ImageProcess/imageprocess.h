#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#define _USE_MATH_DEFINES
#include <QtWidgets/QMainWindow>
#include "ui_imageprocess.h"
#include <QtWidgets/QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets/QFileDialog>
#include <QtGui/QMouseEvent>
#include <math.h>
#include <iostream>

struct Control_Point{
	unsigned x;
	unsigned y;
};

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
	std::vector<Control_Point> linear_points;

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
	void addLinearPointSlot();
	void applyLinearSlot();
	void applyGreyOtherSlot();
	void histogramEqualizationSlot();
	void histogramSpecification_Image_Slot_SML();
	void histogramSpecification_Image_Slot_GML();
	void applySpatialSlot();
	void changeSpatialTemplateSizeSlot(int size);
	void imageSharpeningSlot();

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
	unsigned char getGreyValue(unsigned char r, unsigned char g, unsigned char b);
	unsigned char getNewGreyLinear(unsigned char r, unsigned char g, unsigned char b, Control_Point m, Control_Point n);
	void getRGBbyNewGrey(unsigned char &r, unsigned char &g, unsigned char &b, unsigned newGrey);
	void changeGreyByLog();
	unsigned char getNewGreyLog(unsigned char R, unsigned char G, unsigned char B, double a, double b, double c);
	void changeGreyByExp();
	unsigned char getNewGreyExp(unsigned char R, unsigned char G, unsigned char B, double a, double b, double c);
	void changeGreyByGamma();
	unsigned char getNewGreyGamma(unsigned char R, unsigned char G, unsigned char B, double c, double gamma);
	void getHistogram(double temp[], cv::Mat &im);
	void applyMedianFilter(int templateSize);
	void applyGaussianBlur(int templateSize);
	unsigned char getGaussianValue(unsigned char data[], double factor[], int length);
	void getGaussianFactor(double factor[], int width, int height);
	double getGaussianValueXY(int x, int y);
	void sharpenByRoberts();
	void sharpenByPrewitt();
	void sharpenBySobel();
	void sharpenImage(int factor1[], int factor2[], int maxSize);
};

#endif // IMAGEPROCESS_H

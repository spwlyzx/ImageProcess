#include "imageprocess.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fileOpenSlot()));
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot(){
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	image = cv::imread(fileName.toStdString());
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("读取图片失败，请注意路径中不能含有中文字符.");
		msgBox.exec();
	}
	else
	{	
		displayMat(image);
	}	
}

void ImageProcess::displayMat(cv::Mat origin){
	cv::Mat rgb;
	QImage img;
	if (image.channels() == 3)
	{
		//cvt Mat BGR 2 QImage RGB
		cvtColor(origin, rgb, CV_BGR2RGB);
		img = QImage((const unsigned char*)(rgb.data),
			rgb.cols, rgb.rows,
			rgb.cols*rgb.channels(),
			QImage::Format_RGB888);
	}
	else
	{
		img = QImage((const unsigned char*)(image.data),
			image.cols, image.rows,
			image.cols*image.channels(),
			QImage::Format_RGB888);
	}

	ui.imageLabel->setPixmap(QPixmap::fromImage(img));
	ui.imageLabel->resize(ui.imageLabel->pixmap()->size());

}
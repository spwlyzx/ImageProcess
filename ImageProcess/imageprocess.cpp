#include "imageprocess.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fileOpenSlot()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(fileSaveSlot()));
	connect(ui.actionSave_as, SIGNAL(triggered()), this, SLOT(fileSaveAsSlot()));
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot(){
	filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	image = cv::imread(filename.toStdString());
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("��ȡͼƬʧ�ܣ���ע��·���в��ܺ��������ַ�.");
		msgBox.exec();
	}
	else
	{	
		displayMat(image);
	}	
}

void ImageProcess::fileSaveSlot(){
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("��δ��ȡͼƬ.");
		msgBox.exec();
		return;
	}
	bool result = cv::imwrite(filename.toStdString(), image);
	if (!result)
	{
		QMessageBox msgBox;
		msgBox.setText("д��ʧ�ܣ���ע���Ƿ�������㹻��Ȩ����ԭλ�ý���д�롣");
		msgBox.exec();
	}
}

void ImageProcess::fileSaveAsSlot(){
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("��δ��ȡͼƬ.");
		msgBox.exec();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	bool result = cv::imwrite(fileName.toStdString(), image);
	if (!result)
	{
		QMessageBox msgBox;
		msgBox.setText("����ͼƬʧ�ܣ���ע��·���в��ܺ��������ַ����ļ���Ҫ����.");
		msgBox.exec();
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
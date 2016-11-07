#include "imageprocess.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置显示tooltip
	ui.menuEdit->setToolTipsVisible(true);

	//设置槽的连接关系
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(fileOpenSlot()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(fileSaveSlot()));
	connect(ui.actionSave_as, SIGNAL(triggered()), this, SLOT(fileSaveAsSlot()));
	connect(ui.actionReverse, SIGNAL(triggered()), this, SLOT(editReverseSlot()));
	connect(ui.actionRotate_CW, SIGNAL(triggered()), this, SLOT(editRotateCWSlot()));
	connect(ui.actionRotate_CCW, SIGNAL(triggered()), this, SLOT(editRotateCCWSlot()));
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot()
{
	filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	image = cv::imread(filename.toStdString());
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

void ImageProcess::fileSaveSlot()
{
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("尚未读取图片.");
		msgBox.exec();
		return;
	}
	bool result = cv::imwrite(filename.toStdString(), image);
	if (!result)
	{
		QMessageBox msgBox;
		msgBox.setText("写入失败，请注意是否程序有足够的权限在原位置进行写入。");
		msgBox.exec();
	}
}

void ImageProcess::fileSaveAsSlot()
{
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("尚未读取图片.");
		msgBox.exec();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	bool result = cv::imwrite(fileName.toStdString(), image);
	if (!result)
	{
		QMessageBox msgBox;
		msgBox.setText("保存图片失败，请注意路径中不能含有中文字符，文件名要完整.");
		msgBox.exec();
	}
}

void ImageProcess::editReverseSlot()
{
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("尚未读取图片.");
		msgBox.exec();
		return;
	}

	cv::Mat temp;
	temp.create(image.size(), image.type());
	int nr = image.rows;
	int nl = image.cols*image.channels();
	int chs = image.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = image.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			for (int j = 0; j < chs; j++)
			{
				outData[i + j] = inData[nl - i - chs + j];
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::editRotateCWSlot()
{
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("尚未读取图片.");
		msgBox.exec();
		return;
	}

	cv::Mat temp;
	cv::Size tsize(image.size().height, image.size().width);
	
	temp.create(tsize, image.type());
	int nr = image.rows;
	int nl = image.cols;
	int chs = image.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = image.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			uchar* outData = temp.ptr<uchar>(i);
			for (int j = 0; j < chs; j++)
			{
				outData[(nr - k - 1)*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::editRotateCCWSlot()
{
	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("尚未读取图片.");
		msgBox.exec();
		return;
	}

	cv::Mat temp;
	cv::Size tsize(image.size().height, image.size().width);

	temp.create(tsize, image.type());
	int nr = image.rows;
	int nl = image.cols;
	int chs = image.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = image.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			uchar* outData = temp.ptr<uchar>(nl - i - 1);
			for (int j = 0; j < chs; j++)
			{
				outData[k*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::displayMat(cv::Mat origin)
{
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
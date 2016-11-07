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
	connect(ui.actionChoose_Clip_Area, SIGNAL(triggered()), this, SLOT(editChooseAreaSlot()));
	connect(ui.actionExit_Choose, SIGNAL(triggered()), this, SLOT(editExitClipSlot()));
	connect(ui.actionClip, SIGNAL(triggered()), this, SLOT(editClipSlot()));

	rubberBand = new QRubberBand(QRubberBand::Rectangle, ui.imageLabel);
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot()
{
	filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	image = cv::imread(filename.toStdString());

	editExitClipSlot();

	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("读取图片失败，请注意路径中不能含有中文字符.");
		msgBox.exec();
	}
	else
	{	
		displayMat(image);
		ui.actionReverse->setEnabled(true);
		ui.actionRotate_CW->setEnabled(true);
		ui.actionRotate_CCW->setEnabled(true);
		ui.actionSave->setEnabled(true);
		ui.actionSave_as->setEnabled(true);
		ui.actionChoose_Clip_Area->setEnabled(true);
	}	
}

void ImageProcess::fileSaveSlot()
{
	if (!image.data)
	{
		assertNoFile();
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
		assertNoFile();
		return;
	}
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	bool result = cv::imwrite(fileName.toStdString(), image);
	if (!result)
	{
		QMessageBox msgBox;
		msgBox.setText("保存图片失败，请注意路径中不能含有中文字符，文件名要完整，并请注意程序是否有足够的权限在该位置进行写入。");
		msgBox.exec();
	}
}

void ImageProcess::editReverseSlot()
{
	if (!image.data)
	{
		assertNoFile();
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
		assertNoFile();
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
		assertNoFile();
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

void ImageProcess::editChooseAreaSlot()
{
	if (!image.data)
	{
		assertNoFile();
		return;
	}
	ui.actionClip->setEnabled(true);
	ui.actionExit_Choose->setEnabled(true);
	ui.actionChoose_Clip_Area->setEnabled(false);
	isClipping = true;
}

void ImageProcess::editClipSlot()
{
	cv::Mat temp;
	int top = origin.y() < end.y() ? origin.y() : end.y();
	int bottom = origin.y() + end.y() - top;
	int left = origin.x() < end.x() ? origin.x() : end.x();
	int right = origin.x() + end.x() - left;
	int width = right - left + 1;
	int height = bottom - top + 1;
	cv::Size tsize(width, height);
	temp.create(tsize, image.type());

	int nr = image.rows;
	int nl = image.cols;
	int chs = image.channels();
	for (int k = top; k <= bottom && k < nr; k++)
	{
		const uchar* inData = image.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k-top);
		for (int i = left; i <= right && i < nl; i++)
		{
			for (int j = 0; j < chs; j++)
			{
				outData[(i-left)*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
	editExitClipSlot();
}

void ImageProcess::editExitClipSlot()
{
	isClipping = false;
	rubberBand->hide();
	origin = QPoint(0, 0);
	end = QPoint(0, 0);
	ui.actionClip->setEnabled(false);
	ui.actionExit_Choose->setEnabled(false);
	ui.actionChoose_Clip_Area->setEnabled(true);
}

void ImageProcess::mousePressEvent(QMouseEvent *event)
{
	if (isClipping)
	{
		origin = event->pos();
		origin.setY(origin.y() - ui.centralWidget->y());
		end = QPoint(0, 0);
		rubberBand->setGeometry(QRect(origin, QSize(0, 0)));
		rubberBand->show();
	}
}

void ImageProcess::mouseMoveEvent(QMouseEvent *event)
{
	if (isClipping)
	{
		end = event->pos();
		end.setY(end.y() - ui.centralWidget->y());
		rubberBand->setGeometry(QRect(origin, end).normalized());
	}
}

void ImageProcess::mouseReleaseEvent(QMouseEvent *event)
{
	limit(origin);
	limit(end);
	rubberBand->setGeometry(QRect(origin, end).normalized());
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

	QSize tsize(image.size().width, image.size().height);

	ui.imageLabel->setPixmap(QPixmap::fromImage(img));
	ui.imageLabel->resize(tsize);

}

void ImageProcess::assertNoFile()
{
	QMessageBox msgBox;
	msgBox.setText("尚未读取图片.");
	msgBox.exec();
}

void ImageProcess::limit(QPoint &x)
{
	int max_x = ui.imageLabel->width();
	int max_y = ui.imageLabel->height();
	if (x.x() > max_x){
		x.setX(max_x);
	}
	if (x.y() > max_y){
		x.setY(max_y);
	}
}
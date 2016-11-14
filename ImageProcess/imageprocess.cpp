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

	connect(ui.intSlider, SIGNAL(valueChanged(int)), this, SLOT(changeIntensitySlot(int)));
	connect(ui.intButton, SIGNAL(clicked()), this, SLOT(changeIntensityButtonSlot()));

	connect(ui.satSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSaturationSlot(int)));
	connect(ui.satButton, SIGNAL(clicked()), this, SLOT(changeSaturationButtonSlot()));

	connect(ui.hueSlider, SIGNAL(valueChanged(int)), this, SLOT(changeHueSlot(int)));
	connect(ui.hueButton, SIGNAL(clicked()), this, SLOT(changeHueButtonSlot()));

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
	image.copyTo(originImage);

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
		ui.tabWidget->setEnabled(true);
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
	
	temp.create(originImage.size(), originImage.type());
	nr = originImage.rows;
	nl = originImage.cols*originImage.channels();
	chs = originImage.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			for (int j = 0; j < chs; j++)
			{
				outData[i + j] = inData[nl - i - chs + j];
			}
		}
	}
	temp.copyTo(originImage);

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

	temp.create(tsize, originImage.type());
	nr = originImage.rows;
	nl = originImage.cols;
	chs = originImage.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			uchar* outData = temp.ptr<uchar>(i);
			for (int j = 0; j < chs; j++)
			{
				outData[(nr - k - 1)*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(originImage);

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
	
	temp.create(tsize, originImage.type());
	nr = originImage.rows;
	nl = originImage.cols;
	chs = originImage.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		for (int i = 0; i < nl; i++)
		{
			uchar* outData = temp.ptr<uchar>(nl - i - 1);
			for (int j = 0; j < chs; j++)
			{
				outData[k*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(originImage);

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
	
	temp.create(tsize, originImage.type());
	nr = originImage.rows;
	nl = originImage.cols;
	chs = originImage.channels();
	for (int k = top; k <= bottom && k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k - top);
		for (int i = left; i <= right && i < nl; i++)
		{
			for (int j = 0; j < chs; j++)
			{
				outData[(i - left)*chs + j] = inData[i*chs + j];
			}
		}
	}
	temp.copyTo(originImage);

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

void ImageProcess::changeIntensitySlot(int change)
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeIntensity(change);
	ui.intInput->setValue(change);
}

void ImageProcess::changeIntensityButtonSlot()
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeIntensity(ui.intInput->value());
	ui.intSlider->setValue(ui.intInput->value());
}

void ImageProcess::changeSaturationSlot(int change)
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeSaturation(change);
	ui.satInput->setValue(change);
}

void ImageProcess::changeSaturationButtonSlot()
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeSaturation(ui.satInput->value());
	ui.satSlider->setValue(ui.satInput->value());
}

void ImageProcess::changeHueSlot(int change)
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeHue(change);
	ui.hueInput->setValue(change);
}

void ImageProcess::changeHueButtonSlot()
{
	if (!originImage.data)
	{
		assertNoFile();
		return;
	}

	changeHue(ui.hueInput->value());
	ui.hueSlider->setValue(ui.hueInput->value());
}

void ImageProcess::mousePressEvent(QMouseEvent *event)
{
	if (isClipping)
	{
		origin = event->pos();
		origin.setY(origin.y() - ui.centralWidget->y() - ui.tabWidget->height());
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
		end.setY(end.y() - ui.centralWidget->y() - ui.tabWidget->height());
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

	if (imageSize.isNull() || imageSize.height() == 0 || imageSize != tsize){
ui.imageLabel->resize(tsize);
imageSize = tsize;
resizeMain();
	}
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

void ImageProcess::resizeMain()
{
	QSize temp(0, 0);
	int width = imageSize.width() < ui.tabWidget->width() ? ui.tabWidget->width() : imageSize.width();
	temp.setWidth(width);
	temp.setHeight(imageSize.height() + ui.tabWidget->height());
	ui.centralWidget->resize(temp);

	temp.setHeight(temp.height() + ui.menuBar->height() + ui.statusBar->height());
	this->resize(temp);
}

void ImageProcess::changeIntensity(int change)
{
	cv::Mat temp;
	temp.create(originImage.size(), originImage.type());
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			for (int j = 0; j < chs; j++)
			{
				if (change < 0 && inData[i + j] < -change){
					outData[i + j] = 0;
				}
				else if (change > 0 && inData[i + j]>255 - change){
					outData[i + j] = 255;
				}
				else{
					outData[i + j] = inData[i + j] + change;
				}
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::changeSaturation(int change)
{
	double increment = change / (double)100;

	cv::Mat temp;
	temp.create(originImage.size(), originImage.type());
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	int r, g, b, rgbMax, rgbMin;
	double Delta, mid, L, S, alpha;
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			b = inData[i + 0];
			g = inData[i + 1];
			r = inData[i + 2];
			rgbMax = max(r, g, b);
			rgbMin = min(r, g, b);
			Delta = (rgbMax - rgbMin) / (double)255;
			if (Delta == 0)
			{
				outData[i + 0] = b;
				outData[i + 1] = g;
				outData[i + 2] = r;
			}
			else{
				mid = (rgbMax + rgbMin) / (double)255;
				L = mid / 2;
				if(L < 0.5){
					S = Delta / mid;
				}
				else{
					S = Delta / (2 - mid);
				}
				if (increment >= 0){
					if ((increment + S) >= 1){
						alpha = S;
					}
					else{
						alpha = 1 - increment;
					}
					alpha = 1 / alpha - 1;
					outData[i + 2] = r + (r - L * 255) * alpha;
					outData[i + 1] = g + (g - L * 255) * alpha;
					outData[i + 0] = b + (b - L * 255) * alpha;
				}
				else{
					alpha = increment;
					outData[i + 2] = L * 255 + (r - L * 255) * (1 + alpha);
					outData[i + 1] = L * 255 + (g - L * 255) * (1 + alpha);
					outData[i + 0] = L * 255 + (b - L * 255) * (1 + alpha);
				}
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::changeHue(int change)
{
	cv::Mat temp;
	temp.create(originImage.size(), originImage.type());
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	unsigned char r, g, b, h, s, v;
	double tc = change / (double)360;
	tc = tc * 255;
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			b = inData[i + 0];
			g = inData[i + 1];
			r = inData[i + 2];
			RgbToHsv(r, g, b, h, s, v);
			h = h + tc;
			HsvToRgb(r, g, b, h, s, v);
			outData[i + 0] = b;
			outData[i + 1] = g;
			outData[i + 2] = r;
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

int ImageProcess::max(int a, int b, int c)
{
	int temp = a > b ? a : b;
	return temp > c ? temp : c;
}

int ImageProcess::min(int a, int b, int c)
{
	int temp = a < b ? a : b;
	return temp < c ? temp : c;
}

void ImageProcess::HsvToRgb(unsigned char &r, unsigned char &g, unsigned char &b, unsigned char h, unsigned char s, unsigned char v)
{
	unsigned char region, remainder, p, q, t;

	if (s == 0)
	{
		r = v;
		g = v;
		b = v;
		return ;
	}

	region = h / 43;
	remainder = (h - (region * 43)) * 6;

	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * remainder) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

	switch (region)
	{
	case 0:
		r = v; g = t; b = p;
		break;
	case 1:
		r = q; g = v; b = p;
		break;
	case 2:
		r = p; g = v; b = t;
		break;
	case 3:
		r = p; g = q; b = v;
		break;
	case 4:
		r = t; g = p; b = v;
		break;
	default:
		r = v; g = p; b = q;
		break;
	}
}

void ImageProcess::RgbToHsv(unsigned char r, unsigned char g, unsigned char b, unsigned char &h, unsigned char &s, unsigned char &v)
{
	unsigned char rgbMin, rgbMax;

	rgbMin = r < g ? (r < b ? r : b) : (g < b ? g : b);
	rgbMax = r > g ? (r > b ? r : b) : (g > b ? g : b);

	v = rgbMax;
	if (v == 0)
	{
		h = 0;
		s = 0;
		return;
	}

	s = 255 * long(rgbMax - rgbMin) / v;
	if (s == 0)
	{
		h = 0;
		return;
	}

	if (rgbMax == r)
		h = 0 + 43 * (g - b) / (rgbMax - rgbMin);
	else if (rgbMax == g)
		h = 85 + 43 * (b - r) / (rgbMax - rgbMin);
	else
		h = 171 + 43 * (r - g) / (rgbMax - rgbMin);
}
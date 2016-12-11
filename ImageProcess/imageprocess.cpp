#include "imageprocess.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

using namespace cv;


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

	connect(ui.Linear_add, SIGNAL(clicked()), this, SLOT(addLinearPointSlot()));
	connect(ui.Linear_apply, SIGNAL(clicked()), this, SLOT(applyLinearSlot()));

	connect(ui.Grey_apply, SIGNAL(clicked()), this, SLOT(applyGreyOtherSlot()));

	connect(ui.actionHistogram_Equalization, SIGNAL(triggered()), this, SLOT(histogramEqualizationSlot()));
	connect(ui.actionChoose_a_image_SML, SIGNAL(triggered()), this, SLOT(histogramSpecification_Image_Slot_SML()));
	connect(ui.actionChoose_a_image_GML, SIGNAL(triggered()), this, SLOT(histogramSpecification_Image_Slot_GML()));

	connect(ui.SpatialTemplateSize, SIGNAL(valueChanged(int)), this, SLOT(changeSpatialTemplateSizeSlot(int)));
	connect(ui.ImageSharpening, SIGNAL(clicked()), this, SLOT(imageSharpeningSlot()));
	connect(ui.SpatialApply, SIGNAL(clicked()), this, SLOT(applySpatialSlot()));

	connect(ui.FrequencyApply, SIGNAL(clicked()), this, SLOT(GaussianFrequencySlot()));

	rubberBand = new QRubberBand(QRubberBand::Rectangle, ui.imageLabel);
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot()
{
	filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	image = imread(filename.toStdString());
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
		ui.actionHistogram_Equalization->setEnabled(true);
		ui.actionChoose_a_image_SML->setEnabled(true);
		ui.actionChoose_a_image_GML->setEnabled(true);
		ui.tabWidget->setEnabled(true);
		Control_Point temp1, temp2;
		temp1.x = 0;
		temp1.y = 0;
		temp2.x = 255;
		temp2.y = 255;
		linear_points.push_back(temp1);
		linear_points.push_back(temp2);
	}
}

void ImageProcess::fileSaveSlot()
{
	if (!image.data)
	{
		assertNoFile();
		return;
	}
	bool result = imwrite(filename.toStdString(), image);
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
	bool result = imwrite(fileName.toStdString(), image);
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

	Mat temp;
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

	Mat temp;
	Size tsize(image.size().height, image.size().width);
	
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

	Mat temp;
	Size tsize(image.size().height, image.size().width);

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
	Mat temp;
	int top = origin.y() < end.y() ? origin.y() : end.y();
	int bottom = origin.y() + end.y() - top;
	int left = origin.x() < end.x() ? origin.x() : end.x();
	int right = origin.x() + end.x() - left;
	int width = right - left + 1;
	int height = bottom - top + 1;
	Size tsize(width, height);

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

void ImageProcess::addLinearPointSlot()
{
	Control_Point cp;
	cp.x = (int)ui.Linear_x->value();
	cp.y = (int)ui.Linear_y->value();
	for (int i = 0; i < linear_points.size(); i++){
		if (linear_points[i].x == cp.x && linear_points[i].y == cp.y){
			QMessageBox msgBox;
			msgBox.setText("无法插入重复点。");
			msgBox.exec();
		}
		if (linear_points[i].x > cp.x && linear_points[i].y < cp.y || linear_points[i].x < cp.x && linear_points[i].y > cp.y){
			QMessageBox msgBox;
			msgBox.setText("插入点后的分段函数必须是递增函数。");
			msgBox.exec();
		}
	}
	linear_points.push_back(cp);
	QString temp = ui.Linear_points->toPlainText();
	if (temp.length() > 1){
		temp = temp + "\r\n";
	}
	char temp2[10];
	itoa(linear_points.size()-2,temp2,10);
	temp = temp + "Point " + temp2;
	itoa((int)cp.x, temp2, 10);
	temp = temp + ":(" + temp2;
	itoa((int)cp.y, temp2, 10);
	temp = temp + "," + temp2 + ")";
	ui.Linear_points->setPlainText(temp);
}

void ImageProcess::applyLinearSlot()
{
	for (int i = 0; i < linear_points.size(); i++){
		for (int j = i + 1; j < linear_points.size(); j++)
		{
			if (linear_points[i].x > linear_points[j].x){
				Control_Point temp = linear_points[i];
				linear_points[i] = linear_points[j];
				linear_points[j] = temp;
			}
		}
	}
	Mat temp;
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
			unsigned char b = inData[i + 0];
			unsigned char g = inData[i + 1];
			unsigned char r = inData[i + 2];
			unsigned char grey = getGreyValue(r, g, b);
			int j = 0;
			for (; j < linear_points.size(); j++){
				if (linear_points[j].x>grey){
					break;
				}
			}
			unsigned char newGrey = getNewGreyLinear(r,g,b,linear_points[j-1],linear_points[j]);
			getRGBbyNewGrey(r,g,b,newGrey);
			outData[i + 0] = b;
			outData[i + 1] = g;
			outData[i + 2] = r;
		}
	}
	temp.copyTo(image);
	temp.copyTo(originImage);
	displayMat(image);
}

void ImageProcess::applyGreyOtherSlot()
{
	int method = ui.GreyMethods->currentIndex();
	switch (method){
		case 0: changeGreyByLog(); break;
		case 1: changeGreyByExp(); break;
		case 2: changeGreyByGamma(); break;
		default: break;
	}
}

void ImageProcess::histogramEqualizationSlot()
{
	Mat temp;
	temp.create(originImage.size(), originImage.type());
	double p[256] = { 0 };
	getHistogram(p, originImage);
	
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();

	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];
			unsigned char grey = getGreyValue(R, G, B);
			unsigned char newGrey = p[grey] * 255;
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp.copyTo(image);
	temp.copyTo(originImage);
	displayMat(image);
}

void ImageProcess::histogramSpecification_Image_Slot_SML()
{
	filename = QFileDialog::getOpenFileName(this, tr("Choose Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	Mat temp = imread(filename.toStdString());

	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("读取图片失败，请注意路径中不能含有中文字符.");
		msgBox.exec();
		return;
	}

	double p[256] = { 0 };
	double q[256] = { 0 };
	double srcMin[256][256] = { 0 };
	int Mapping[256] = { 0 };

	getHistogram(p, originImage);
	getHistogram(q, temp);

	double scrMin[256][256];
	for (int y = 0; y < 256; y++){
		for (int x = 0; x < 256; x++){
			srcMin[x][y] = fabs(p[y] - q[x]);
		}
	}
	for (int y = 0; y < 256; y++){
		int minX = 0;
		double minValue = srcMin[0][y];
		for (int x = 1; x < 256; x++){
			if (minValue > srcMin[x][y]){
				minValue = srcMin[x][y];
				minX = x;
			}
		}
		Mapping[y] = minX;
	}

	Mat temp2;
	temp2.create(originImage.size(), originImage.type());

	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();

	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp2.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];
			unsigned char grey = getGreyValue(R, G, B);
			unsigned char newGrey = q[Mapping[grey]]*255;
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp2.copyTo(image);
	temp2.copyTo(originImage);
	displayMat(image);
}

void ImageProcess::histogramSpecification_Image_Slot_GML()
{
	filename = QFileDialog::getOpenFileName(this, tr("Choose Image"),
		".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	Mat temp = imread(filename.toStdString());

	if (!image.data)
	{
		QMessageBox msgBox;
		msgBox.setText("读取图片失败，请注意路径中不能含有中文字符.");
		msgBox.exec();
		return;
	}

	double p[256] = { 0 };
	double q[256] = { 0 };
	double srcMin[256][256] = { 0 };
	int Mapping[256] = { 0 };

	getHistogram(p, originImage);
	getHistogram(q, temp);

	double scrMin[256][256];
	for (int y = 0; y < 256; y++){
		for (int x = 0; x < 256; x++){
			srcMin[x][y] = fabs(p[y] - q[x]);
		}
	}

	int lastStartY = 0, lastEndY = 0, startY = 0, endY = 0;
	for (int x = 0; x < 256; x++){
		double minValue = srcMin[x][0];
		for (int y = 0; y < 256; y++){
			if (minValue > srcMin[x][y]){
				endY = y;
				minValue = srcMin[x][y];
			}
		}
		if (startY != lastStartY || endY != lastEndY){
			for (int i = startY; i <= endY; i++){
				Mapping[i] = x;
			}
			lastStartY = startY;
			lastEndY = endY;
			startY = lastEndY + 1;
		}
	}

	Mat temp2;
	temp2.create(originImage.size(), originImage.type());

	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();

	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = originImage.ptr<uchar>(k);
		uchar* outData = temp2.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];
			unsigned char grey = getGreyValue(R, G, B);
			unsigned char newGrey = q[Mapping[grey]] * 255;
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp2.copyTo(image);
	temp2.copyTo(originImage);
	displayMat(image);
}

void ImageProcess::applySpatialSlot()
{
	int method = ui.SpatialType->currentIndex();
	int size = ui.SpatialTemplateSize->value();
	switch (method)
	{
	case 0:applyMedianFilter(size); break;
	case 1:applyGaussianBlur(size); break;
	default:
		break;
	}
}

void ImageProcess::changeSpatialTemplateSizeSlot(int size)
{
	if (size % 2 == 0){
		size = size + 1;
		ui.SpatialTemplateSize->setValue(size);
		return;
	}
	char temp[10];
	itoa(size, temp, 10);
	ui.SpatialSizeLabel->setText(temp);
}

void ImageProcess::imageSharpeningSlot()
{
	int method = ui.ImageSharpeningFactor->currentIndex();
	switch (method)
	{
	case 0:sharpenByRoberts(); break;
	case 1:sharpenByPrewitt(); break;
	case 2:sharpenBySobel(); break;
	default:
		break;
	}
}

void ImageProcess::GaussianFrequencySlot()
{
	int method = ui.FrequencyFilterType->currentIndex();
	int D0 = ui.FrequencyD0->value();
	GaussianFrequency(method,D0);
	if (method == 1){

	}
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

void ImageProcess::displayMat(Mat origin)
{
	Mat rgb;
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
	Mat temp;
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

	Mat temp;
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
	Mat temp;
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

unsigned char ImageProcess::getGreyValue(unsigned char r, unsigned char g, unsigned char b)
{
	double tr = 0.11 * r;
	double tg = 0.59 * g;
	double tb = 0.3 * b;
	return tr + tg + tb;
}

unsigned char ImageProcess::getNewGreyLinear(unsigned char r, unsigned char g, unsigned char b, Control_Point m, Control_Point n)
{
	double newGrey = 0;
	if (m.y == n.y)
	{
		newGrey = m.y;
	}
	else
	{
		unsigned char grey = getGreyValue(r, g, b);
		double lean = (n.y - m.y) / (double)(n.x - m.x);
		newGrey = lean * (grey - m.x) + m.y;
	}
	return newGrey;
}

void ImageProcess::getRGBbyNewGrey(unsigned char &r, unsigned char &g, unsigned char &b, unsigned newGrey)
{
	double ratio = newGrey / (double) getGreyValue(r,g,b);
	r = ratio *r > 255 ? 255 : ratio*r;
	g = ratio *g > 255 ? 255 : ratio*g;
	b = ratio *b > 255 ? 255 : ratio*b;
}

void ImageProcess::changeGreyByLog()
{
	double a = ui.Grey_a->value();
	double b = ui.Grey_b->value();
	double c = ui.Grey_c->value();
	Mat temp;
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
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];

			unsigned char newGrey = getNewGreyLog(R, G, B, a, b, c);
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp.copyTo(image);
	temp.copyTo(originImage);
	displayMat(image);
}

unsigned char ImageProcess::getNewGreyLog(unsigned char R, unsigned char G, unsigned char B, double a, double b, double c)
{
	unsigned char grey = getGreyValue(R, G, B);
	double toReturn = a + log((double)((int)grey + 1)) / (b * log(c)); 
	return toReturn;
}

void ImageProcess::changeGreyByExp()
{
	double a = ui.Grey_a->value();
	double b = ui.Grey_b->value();
	double c = ui.Grey_c->value();
	Mat temp;
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
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];

			unsigned char newGrey = getNewGreyExp(R, G, B, a, b, c);
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp.copyTo(image);
	temp.copyTo(originImage);
	displayMat(image);
}

unsigned char ImageProcess::getNewGreyExp(unsigned char R, unsigned char G, unsigned char B, double a, double b, double c)
{
	unsigned char grey = getGreyValue(R, G, B);
	double toReturn = pow(b, c*(grey - a)) - 1;
	return toReturn;
}

void ImageProcess::changeGreyByGamma()
{
	double gamma = ui.Grey_gamma->value();
	double c = ui.Grey_c->value();
	Mat temp;
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
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];

			unsigned char newGrey = getNewGreyGamma(R, G, B, c, gamma);
			getRGBbyNewGrey(R, G, B, newGrey);
			outData[i + 0] = B;
			outData[i + 1] = G;
			outData[i + 2] = R;
		}
	}
	temp.copyTo(image);
	temp.copyTo(originImage);
	displayMat(image);
}

unsigned char ImageProcess::getNewGreyGamma(unsigned char R, unsigned char G, unsigned char B, double c, double gamma)
{
	unsigned char grey = getGreyValue(R, G, B);
	double ratio = grey / (double)255;
	double s = c*pow(ratio,gamma);
	return s*255;
}

void ImageProcess::getHistogram(double temp[], Mat &im)
{
	int nr = im.rows;
	int nl = im.cols*im.channels();
	int chs = im.channels();
	for (int k = 0; k < nr; k++)
	{
		const uchar* inData = im.ptr<uchar>(k);
		for (int i = 0; i < nl; i += chs)
		{
			unsigned char B = inData[i + 0];
			unsigned char G = inData[i + 1];
			unsigned char R = inData[i + 2];

			unsigned char grey = getGreyValue(R, G, B);
			temp[grey]++;
		}
	}
	for (int i = 0; i < 256; i++){
		temp[i] = temp[i] / (nl*nr / 3);
	}
	for (int i = 1; i < 256; i++){
		temp[i] = temp[i] + temp[i - 1];
	}
}

void ImageProcess::applyMedianFilter(int templateSize)
{
	Mat temp;
	temp.create(originImage.size(), originImage.type());
	int half = templateSize / 2;
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	int count[256] = { 0 };
	for (int k = 0; k < nr; k++)
	{
		uchar* outData = temp.ptr<uchar>(k);
		if (k - half < 0 || k + half >= nr)
		{
			const uchar* inData = originImage.ptr<uchar>(k);
			for (int i = 0; i < nl; i += chs)
			{
				for (int j = 0; j < chs; j++)
				{
					outData[i + j] = inData[i + j];
				}
			}
		}
		else
		{
			for (int i = 0; i < nl; i += chs)
			{
				if (i - half * 3 < 0 || i + half * 3 >= nl)
				{
					const uchar* inData = originImage.ptr<uchar>(k);
					for (int j = 0; j < chs; j++)
					{
						outData[i + j] = inData[i + j];
					}
				}
				else
				{
					for (int j = 0; j < chs; j++)
					{
						for (int tk = k - half; tk <= k + half; tk++)
						{
							const uchar* inData = originImage.ptr<uchar>(tk);
							for (int ti = i - half * 3; ti <= i + half * 3; ti = ti + 3)
							{
								count[(int)inData[ti + j]] = count[(int)inData[ti + j]] + 1;
							}
						}
						int tempCount = (templateSize*templateSize + 1) / 2;
						unsigned char mid = 0;
						for (int m = 0; m < 256; m++){
							if (count[m] == 0){
								continue;
							}
							if (tempCount > 0){
								tempCount = tempCount - count[m];
								if (tempCount <= 0){
									mid = m;
								}
							}
							count[m] = 0;
						}
						outData[i + j] = mid;
					}
				}
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::applyGaussianBlur(int templateSize)
{
	Mat temp;
	temp.create(originImage.size(), originImage.type());
	int half = templateSize / 2;
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	double *factors = new double[templateSize*templateSize];
	getGaussianFactor(factors, templateSize, templateSize);
	for (int k = 0; k < nr; k++)
	{
		uchar* outData = temp.ptr<uchar>(k);
		if (k - half < 0 || k + half >= nr)
		{
			const uchar* inData = originImage.ptr<uchar>(k);
			for (int i = 0; i < nl; i += chs)
			{
				for (int j = 0; j < chs; j++)
				{
					outData[i + j] = inData[i + j];
				}
			}
		}
		else
		{
			for (int i = 0; i < nl; i += chs)
			{
				if (i - half * 3 < 0 || i + half * 3 >= nl)
				{
					const uchar* inData = originImage.ptr<uchar>(k);
					for (int j = 0; j < chs; j++)
					{
						outData[i + j] = inData[i + j];
					}
				}
				else
				{
					for (int j = 0; j < chs; j++)
					{
						unsigned char *tempArray = new unsigned char[templateSize*templateSize];
						int index = 0;
						for (int tk = k - half; tk <= k + half; tk++)
						{
							const uchar* inData = originImage.ptr<uchar>(tk);
							for (int ti = i - half * 3; ti <= i + half * 3; ti = ti + 3)
							{
								tempArray[index] = inData[ti + j];
								index++;
							}
						}
						outData[i + j] = getGaussianValue(tempArray, factors, templateSize*templateSize);
					}
				}
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

unsigned char ImageProcess::getGaussianValue(unsigned char data[], double factor[],int length)
{
	double toReturn = 0;
	for (int i = 0; i < length; i++){
		toReturn += factor[i] * data[i];
	}
	return toReturn;
}

void ImageProcess::getGaussianFactor(double factor[], int width, int height)
{
	double total = 0;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			factor[i*width + j] = getGaussianValueXY(j-width/2,i-width/2);
			total += factor[i*width + j];
		}
	}
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			factor[i*width + j] = factor[i*width + j] / total;
		}
	}
}

double ImageProcess::getGaussianValueXY(int x, int y)
{
	double theta2 = 1.5*1.5;
	double factor = 1 / (2 * M_PI*theta2);
	double right = exp(-(x*x + y*y) / (2 * theta2));
	return factor*right;
}

void ImageProcess::sharpenByRoberts()
{
	int a[] = { 0, 0, 0,
				0, 1, 0,
				0, 0, -1 };
	int b[] = { 0, 0, 0,
				0, 0, 1,
				0, -1, 0 };
	sharpenImage(a, b, 2);
}

void ImageProcess::sharpenByPrewitt()
{
	int a[] = { -1, -1, -1,
				0, 0, 0,
				1, 1, 1 };
	int b[] = { -1, 0, 1,
				-1, 0, 1,
				-1, 0, 1 };
	sharpenImage(a, b, 4);
}

void ImageProcess::sharpenBySobel()
{
	int a[] = { -1, -2, -1,
				0, 0, 0,
				1, 2, 1 };
	int b[] = { -1, 0, 1,
				-2, 0, 2,
				-1, 0, 1 };
	sharpenImage(a, b, 6);
}

void ImageProcess::sharpenImage(int factor1[], int factor2[], int maxSize)
{
	Mat temp;
	temp.create(originImage.size(), originImage.type());
	int nr = originImage.rows;
	int nl = originImage.cols*originImage.channels();
	int chs = originImage.channels();
	for (int k = 0; k < nr; k++)
	{
		uchar* outData = temp.ptr<uchar>(k);
		if (k - 1 < 0 || k + 1 >= nr)
		{
			const uchar* inData = originImage.ptr<uchar>(k);
			for (int i = 0; i < nl; i += chs)
			{
				for (int j = 0; j < chs; j++)
				{
					outData[i + j] = inData[i + j];
				}
			}
		}
		else
		{
			for (int i = 0; i < nl; i += chs)
			{
				if (i - 3 < 0 || i + 3 >= nl)
				{
					const uchar* inData = originImage.ptr<uchar>(k);
					for (int j = 0; j < chs; j++)
					{
						outData[i + j] = inData[i + j];
					}
				}
				else
				{
					int tempArray[9];
					int index = 0;
					unsigned char H, S, V, R, G, B;
					for (int tk = k - 1; tk <= k + 1; tk++)
					{
						const uchar* inData = originImage.ptr<uchar>(tk);
						for (int ti = i - 3; ti <= i + 3; ti = ti + 3)
						{
							R = inData[ti + 2];
							G = inData[ti + 1];
							B = inData[ti + 0];
							RgbToHsv(R, G, B, H, S, V);
							tempArray[index] = V;
							index++;
						}
					}
					int tempf1 = 0;
					for (int m = 0; m < 9; m++){
						tempf1 += factor1[m] * tempArray[m];
					}
					int tempf2 = 0;
					for (int m = 0; m < 9; m++){
						tempf2 += factor2[m] * tempArray[m];
					}
					const uchar* tempData = originImage.ptr<uchar>(k);
					double factor = abs(tempf1) + abs(tempf2);
					R = tempData[i + 2];
					G = tempData[i + 1];
					B = tempData[i + 0];
					RgbToHsv(R, G, B, H, S, V);
					if (factor / maxSize > 30){
						factor = (factor / 2) / maxSize + V;
						V = factor > 255 ? 255 : factor;
					}
					HsvToRgb(R, G, B, H, S, V);
					outData[i + 2] = R;
					outData[i + 1] = G;
					outData[i + 0] = B;
				}
			}
		}
	}
	temp.copyTo(image);
	displayMat(image);
}

void ImageProcess::GaussianFrequency(int flag, int D0)
{
	Mat record = originImage.clone();

	vector<Mat> channels(3);
	split(record, channels);

	for (int num = 0; num < 3; num++){
		Mat value;
		channels[num].convertTo(value, CV_64FC1, 1 / 255.0);

		Mat fourier, distance;
		fourier = Fourier(value);
		FourierShift(fourier);

		int m_c = fourier.rows / 2;
		int n_c = fourier.cols / 2;
		for (int i = 0; i < fourier.rows; i++)
		{
			for (int j = 0; j < fourier.cols; j++)
			{
				double d, h;
				if (flag == 0)
				{
					d = sqrt((double)(i - m_c) *(i - m_c) + (j - n_c)*(j - n_c));
					h = exp(-pow(d / D0, 2) / 2);
				}
				else if (flag == 1)
				{
					d = sqrt((double)(i - m_c) *(i - m_c) + (j - n_c)*(j - n_c));
					h = exp(-pow(d / D0, 2) / 2);
					h = 1 - h;
				}
				//ButterWorth
				//double d = sqrt((double)(i - m_c) *(i - m_c) + (j - n_c)*(j - n_c));
				//double h = 1 / pow(1 + (d / d0), (2 * n));

				fourier.at<Vec2d>(i, j)[0] = h*fourier.at<Vec2d>(i, j)[0];
				fourier.at<Vec2d>(i, j)[1] = h*fourier.at<Vec2d>(i, j)[1];
			}
		}

		FourierShift(fourier);

		idft(fourier, fourier);

		Mat planes[2];
		planes[0] = Mat_<double>(channels[num]);
		planes[1] = Mat::zeros(channels[num].size(), CV_64F);
		split(fourier,planes);

		normalize(planes[0],distance,0,1,CV_MINMAX);

		for (int i = 0; i < image.rows; i++)
		{
			const double* inData = distance.ptr<double>(i);
			uchar* outData = image.ptr<uchar>(i);
			for (int j = 0; j < image.cols; j++)
			{
				int temp3 = inData[j] * 255;
				outData[3*j + num] = (uchar)temp3;
			}
		}
	}
	displayMat(image);
}

Mat ImageProcess::Fourier(Mat img)
{
	Mat image_Re = img;
	Mat image_Im = Mat::zeros(img.rows, img.cols, CV_64FC1);

	Mat complexI(img.rows, img.cols, CV_64FC2);
	
	std::vector<Mat>planes(2);
	planes[0] = image_Re;
	planes[1] = image_Im;
	merge(planes, complexI);

	dft(complexI, complexI);
	return complexI;
}

void ImageProcess::FourierShift(Mat &img)
{
	std::vector<Mat>planes(2);
	split(img, planes);                   // planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))

	Mat image_Re = planes[0];
	Mat image_Im = planes[1];

	///////////////////////Re
	image_Re = image_Re(Rect(0, 0, image_Re.cols & -2, image_Re.rows & -2));
	int cx = image_Re.cols / 2;
	int cy = image_Re.rows / 2;

	Mat q0(image_Re, Rect(0, 0, cx, cy));   // Top-Left - 为每一个象限创建ROI
	Mat q1(image_Re, Rect(cx, 0, cx, cy));  // Top-Right
	Mat q2(image_Re, Rect(0, cy, cx, cy));  // Bottom-Left
	Mat q3(image_Re, Rect(cx, cy, cx, cy)); // Bottom-Right

	Mat tmp;                           

	q0.copyTo(tmp);					   // 交换象限 (Top-Left with Bottom-Right)
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);                    // 交换象限 (Top-Right with Bottom-Left)
	q2.copyTo(q1);
	tmp.copyTo(q2);

	/////////////////////Im
	image_Im = image_Im(Rect(0, 0, image_Im.cols & -2, image_Im.rows & -2));
	int cx2 = image_Im.cols / 2;
	int cy2 = image_Im.rows / 2;

	Mat q02(image_Im, Rect(0, 0, cx2, cy2));   // Top-Left - 为每一个象限创建ROI
	Mat q12(image_Im, Rect(cx2, 0, cx2, cy2));  // Top-Right
	Mat q22(image_Im, Rect(0, cy2, cx2, cy2));  // Bottom-Left
	Mat q32(image_Im, Rect(cx2, cy2, cx2, cy2)); // Bottom-Right

	q02.copyTo(tmp);					   // 交换象限 (Top-Left with Bottom-Right)
	q32.copyTo(q02);
	tmp.copyTo(q32);

	q12.copyTo(tmp);                    // 交换象限 (Top-Right with Bottom-Left)
	q22.copyTo(q12);
	tmp.copyTo(q22);


	planes[0] = image_Re;
	planes[1] = image_Im;

	merge(planes, img);
}

Mat ImageProcess::FourierDistance(Mat img)
{
	Mat image_Re(img.rows, img.cols, CV_64FC1);
	Mat image_Im = Mat::zeros(img.rows, img.cols, CV_64FC1);

	std::vector<Mat>planes(2);
	split(img, planes);
	image_Re = planes[0];
	image_Im = planes[1];

	pow(image_Re, 2, image_Re);
	pow(image_Im, 2, image_Im);
	add(image_Re, image_Im, image_Re);
	pow(image_Re, 0.5, image_Re);

	normalize(image_Re, image_Re, 1, 0, CV_MINMAX);

	return image_Re;
}

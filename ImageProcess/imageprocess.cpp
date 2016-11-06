#include "imageprocess.h"

ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::fileOpenSlot(){
	QMessageBox msgBox;
	msgBox.setText("The document has been modified.");
	msgBox.exec();
}
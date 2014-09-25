#include "PropertyWidget.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
PropertyWidget::PropertyWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//隐藏原标题栏
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	//初始化示波器通道参数
	QList<QString> colorNameList;
	QList<int> wideSpinList;
	initPassageColorSettings(colorNameList, wideSpinList);

	//初始化示波器画布背景参数
	QList<QString> colorNameList_2;
	QList<int> coordinateSpinList;
	initOscPlotSettings(colorNameList_2, coordinateSpinList);
}

PropertyWidget::~PropertyWidget()
{

}
/**
* @brief 设置通道颜色菜单
*/
void PropertyWidget::on_colorBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(0);
}
/**
* @brief 设置文件名格式菜单
*/
void PropertyWidget::on_fileNameBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(1);
}
/**
* @brief 设置中间值菜单
*/
void PropertyWidget::on_midMarkBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(2);
}
void PropertyWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


/**
* @brief 初始通道1颜色
*/
void PropertyWidget::on_colorBtn_1_clicked()
{
	setColorBtn(ui.colorBtn_1);
}
/**
* @brief 给颜色PushButton着色
*/
void PropertyWidget::setColorBtn(QPushButton* btn)
{
	QColor color = QColorDialog::getColor(Qt::white, this);
	QString sheet = QString(" QPushButton{	border: 1px solid white; color:white;background-color:%1;}").arg(color.name());
	btn->setStyleSheet(sheet);
	
}
/**
* @brief 给颜色PushButton着色
*/
void PropertyWidget::setColorBtn(QPushButton* btn,QString name)
{
	QColor color(name);
	QString sheet = QString(" QPushButton{	border: 1px solid white; color:white;background-color:%1;}").arg(color.name());
	btn->setStyleSheet(sheet);

}
/**
* @brief 初始通道2颜色
*/
void PropertyWidget::on_colorBtn_2_clicked()
{
	setColorBtn(ui.colorBtn_2);
}
/**
* @brief 初始通道3颜色
*/
void PropertyWidget::on_colorBtn_3_clicked()
{
	setColorBtn(ui.colorBtn_3);
}
/**
* @brief 初始通道4颜色
*/
void PropertyWidget::on_colorBtn_4_clicked()
{
	setColorBtn(ui.colorBtn_4);
}
/**
* @brief 初始通道5颜色
*/
void PropertyWidget::on_colorBtn_5_clicked()
{
	setColorBtn(ui.colorBtn_5);
}
/**
* @brief 初始通道6颜色
*/
void PropertyWidget::on_colorBtn_6_clicked()
{
	setColorBtn(ui.colorBtn_6);
}
/**
* @brief 初始通道7颜色
*/
void PropertyWidget::on_colorBtn_7_clicked()
{
	setColorBtn(ui.colorBtn_7);
}
/**
* @brief 初始通道8颜色
*/
void PropertyWidget::on_colorBtn_8_clicked()
{
	setColorBtn(ui.colorBtn_8);
}


/**
* @brief 初始通道颜色默认参数
* @param colorNameList 通道颜色
* @param wideSpinList 通道颜色的宽度
*/
void PropertyWidget::initPassageColorSettings(QList<QString>& colorNameList, QList<int>& wideSpinList)
{
	QString colorName;
	colorName = bllSettings.read("PassageColor", "passageColor1").toString();
	setColorBtn(ui.colorBtn_1, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor2").toString();
	setColorBtn(ui.colorBtn_2, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor3").toString();
	setColorBtn(ui.colorBtn_3, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor4").toString();
	setColorBtn(ui.colorBtn_4, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor5").toString();
	setColorBtn(ui.colorBtn_5, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor6").toString();
	setColorBtn(ui.colorBtn_6, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor7").toString();
	setColorBtn(ui.colorBtn_7, colorName);
	colorNameList.append(colorName);
	colorName = bllSettings.read("PassageColor", "passageColor8").toString();
	setColorBtn(ui.colorBtn_8, colorName);
	colorNameList.append(colorName);


	int value = 0;
	value = bllSettings.read("PassageColor", "width1").toInt();
	ui.wideSpinBox_1->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width2").toInt();
	ui.wideSpinBox_2->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width3").toInt();
	ui.wideSpinBox_3->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width4").toInt();
	ui.wideSpinBox_4->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width5").toInt();
	ui.wideSpinBox_5->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width6").toInt();
	ui.wideSpinBox_6->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width7").toInt();
	ui.wideSpinBox_7->setValue(value);
	wideSpinList.append(value);
	value = bllSettings.read("PassageColor", "width8").toInt();
	ui.wideSpinBox_8->setValue(value);
	wideSpinList.append(value);


}
/**
* @brief 更新通道颜色默认参数
*/
void PropertyWidget::updatePassageColorSettings()
{
	QPalette palette = ui.colorBtn_1->palette();
	QColor backGround = palette.color(QPalette::Background);
	QString value = backGround.name();
	bllSettings.update("PassageColor","passageColor1",value);

	palette = ui.colorBtn_2->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor2", value);

	palette = ui.colorBtn_3->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor3", value);

	palette = ui.colorBtn_4->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor4", value);

	palette = ui.colorBtn_5->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor5", value);

	palette = ui.colorBtn_6->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor6", value);

	palette = ui.colorBtn_7->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor7", value);

	palette = ui.colorBtn_8->palette();
	backGround = palette.color(QPalette::Background);
	value = backGround.name();
	bllSettings.update("PassageColor", "passageColor8", value);


	int width = ui.wideSpinBox_1->value();
	bllSettings.update("PassageColor", "width1", width);

	width = ui.wideSpinBox_2->value();
	bllSettings.update("PassageColor", "width2", width);
	width = ui.wideSpinBox_3->value();
	bllSettings.update("PassageColor", "width3", width);
	width = ui.wideSpinBox_4->value();
	bllSettings.update("PassageColor", "width4", width);
	width = ui.wideSpinBox_5->value();
	bllSettings.update("PassageColor", "width5", width);
	width = ui.wideSpinBox_6->value();
	bllSettings.update("PassageColor", "width6", width);
	width = ui.wideSpinBox_7->value();
	bllSettings.update("PassageColor", "width7", width);
	width = ui.wideSpinBox_8->value();
	bllSettings.update("PassageColor", "width8", width);

}
/**
* @brief 确认
*/
void PropertyWidget::on_okBtnProperty_clicked()
{
	int pageIndex = ui.stackedWidgetProperty->currentIndex();
	switch (pageIndex)
	{
	//示波器通道颜色
	case 0:
		updatePassageColorSettings();//更新通道颜色
		emit oscParamChanged();//通知示波器端参数变更
		break;
	//文件名
	case 1:
		break;
	//示波器画布
	case 2:
		updateOscPlotSettings();//更新示波器画布背景参数
		emit oscPlotChanged();
		break;
	default:
		;
	}
	
}
/**
* @brief 取消
*/
void PropertyWidget::on_cancleBtnPropety_clicked()
{
	this->close();
}


/**
* @brief 初始示波器参数
*/
void PropertyWidget::initOscPlotSettings(QList<QString>& colorNameList, QList<int>& coordinateSpinList)
{
	int value = 0;
	value = bllSettings.read("OscPlot", "xLeft").toInt();
	ui.xLeftSpinBox->setValue(value);
	coordinateSpinList.append(value);
	value = bllSettings.read("OscPlot", "xRight").toInt();
	ui.xRightSpinBox->setValue(value);
	coordinateSpinList.append(value);
	value = bllSettings.read("OscPlot", "xStepSize").toInt();
	ui.xStepSizeSpinBox->setValue(value);
	coordinateSpinList.append(value);
	value = bllSettings.read("OscPlot", "yDown").toInt();
	ui.yDownSpinBox->setValue(value);
	coordinateSpinList.append(value);
	value = bllSettings.read("OscPlot", "yTop").toInt();
	ui.yTopSpinBox->setValue(value);
	coordinateSpinList.append(value);
	value = bllSettings.read("OscPlot", "yStepSize").toInt();
	ui.yStepSizeSpinBox->setValue(value);
	coordinateSpinList.append(value);

	QString colorName;
	colorName = bllSettings.read("OscPlot", "oscPlotColor").toString();
	//如果是未自定义，则显示默认颜色
	if (colorName == "#000000")
		on_defaultCheckBox_toggled(true);//当做选中默认checkbox
	else//否则读取自定义色
		setColorBtn(ui.plotColorBtn, colorName);
	colorNameList.append(colorName);


}
/**
* @brief 更新示波器参数
*/
void PropertyWidget::updateOscPlotSettings()
{
	int coordinate = ui.xLeftSpinBox->value();
	bllSettings.update("OscPlot", "xLeft", coordinate);
	coordinate = ui.xRightSpinBox->value();
	bllSettings.update("OscPlot", "xRight", coordinate);
	coordinate = ui.xStepSizeSpinBox->value();
	bllSettings.update("OscPlot", "xStepSize", coordinate);
	coordinate = ui.yDownSpinBox->value();
	bllSettings.update("OscPlot", "yDown", coordinate);
	coordinate = ui.yTopSpinBox->value();
	bllSettings.update("OscPlot", "yTop", coordinate);
	coordinate = ui.yStepSizeSpinBox->value();
	bllSettings.update("OscPlot", "yStepSize", coordinate);
	
	QPalette palette = ui.plotColorBtn->palette();
	QColor backGround = palette.color(QPalette::Background);
	QString value = backGround.name();//如果是默认渐变色，会是#000000
	bllSettings.update("OscPlot", "oscPlotColor", value);
}
/**
* @brief 初始画布背景颜色
*/
void PropertyWidget::on_plotColorBtn_clicked()
{
	setColorBtn(ui.plotColorBtn);
}
/**
* @brief 画布背景默认颜色
*/
void PropertyWidget::on_defaultCheckBox_toggled(bool enable)
{
	if (enable)
	{
		ui.plotColorBtn->setStyleSheet("QPushButton{ border: 1px solid white; color:white; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #00316E, stop:1 #0057AE);}");
		ui.plotColorBtn->setEnabled(false);
	}
	else
	{
		ui.plotColorBtn->setEnabled(true);
	}


}
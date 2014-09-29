#include "PlotConfig.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
PlotConfig::PlotConfig(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//隐藏原标题栏
	//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);


	//初始散点图背景参数
	QMap<QString, QVariant> scatterValueMap;
	initScatterPlotSettings(scatterValueMap);
	//初始直方图背景参数
	QMap<QString, QVariant> barChartValueMap;
	initBarChartPlotSettings(barChartValueMap);

	//初始画布背景参数
	QMap<QString, QVariant> plotValueMap;
	initPlotSettings(plotValueMap);
}

PlotConfig::~PlotConfig()
{

}
/**
* @brief 设置散点图画布参数菜单
*/
void PlotConfig::on_scatterBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(0);
}
/**
* @brief 设置直方图画布参数菜单
*/
void PlotConfig::on_barChartBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(1);
}
/**
* @brief 设置画布参数菜单
*/
void PlotConfig::on_plotBtnProperty_clicked()
{
	ui.stackedWidgetProperty->setCurrentIndex(2);
}
void PlotConfig::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


/**
* @brief 初始直方图颜色
*/
void PlotConfig::on_barChatColorBtn_clicked()
{
	setColorBtn(ui.barChatColorBtn);
}
/**
* @brief 给颜色PushButton着色
*/
void PlotConfig::setColorBtn(QPushButton* btn)
{
	QColor color = QColorDialog::getColor(Qt::white, this);
	QString sheet = QString(" QPushButton{	border: 1px solid white; color:white;background-color:%1;}").arg(color.name());
	btn->setStyleSheet(sheet);
	
}
/**
* @brief 给颜色PushButton着色
*/
void PlotConfig::setColorBtn(QPushButton* btn,QString name)
{
	QColor color(name);
	QString sheet = QString(" QPushButton{	border: 1px solid white; color:white;background-color:%1;}").arg(color.name());
	btn->setStyleSheet(sheet);

}
/**
* @brief 初始散点图颜色
*/
void PlotConfig::on_scatterColorBtn_clicked()
{
	setColorBtn(ui.scatterColorBtn);
}


/**
* @brief 初始散点图Plot默认参数
* @param valueMap 
*/
void PlotConfig::initScatterPlotSettings(QMap<QString,QVariant>& valueMap)
{
	//X轴坐标
	int value = 0;
	value = bllSettings.read("PlotConfig", "xLeftSpinBox").toInt();
	ui.xLeftSpinBox->setValue(value);
	valueMap.insert("xLeftSpinBox",value);
	
	value = bllSettings.read("PlotConfig", "xRightSpinBox").toInt();
	ui.xRightSpinBox->setValue(value);
	valueMap.insert("xRightSpinBox", value);

	value = bllSettings.read("PlotConfig", "xAutoCheckBox").toInt();
	ui.xAutoCheckBox->setChecked(value);//也会激活on_xAutoCheckBox_toggled函数
	valueMap.insert("xAutoCheckBox", value);

	//Y轴坐标
	value = bllSettings.read("PlotConfig", "yDownSpinBox").toInt();
	ui.yDownSpinBox->setValue(value);
	valueMap.insert("yDownSpinBox", value);

	value = bllSettings.read("PlotConfig", "yTopSpinBox").toInt();
	ui.yTopSpinBox->setValue(value);
	valueMap.insert("yTopSpinBox", value);
	value = bllSettings.read("PlotConfig", "yAutoCheckBox").toInt();
	ui.yAutoCheckBox->setChecked(value);//也会激活on_yAutoCheckBox_toggled函数
	valueMap.insert("yAutoCheckBox", value);


	//散点图粗细颜色
	QString colorName;
	colorName = bllSettings.read("PlotConfig", "scatterColorBtn").toString();
	setColorBtn(ui.scatterColorBtn, colorName);
	valueMap.insert("scatterColorBtn", value);

	value = bllSettings.read("PlotConfig", "scatterWideSpinBox").toInt();
	ui.scatterWideSpinBox->setValue(value);
	valueMap.insert("scatterWideSpinBox", value);

	value = bllSettings.read("PlotConfig", "scatterDefaultCheckBox").toInt();
	ui.scatterDefaultCheckBox->setChecked(value);//也会激活on_scatterDefaultCheckBox_toggled函数
	valueMap.insert("scatterDefaultCheckBox", value);




}
/**
* @brief 更新画布默认参数
*/
void PlotConfig::updateScatterPlotSettings()
{
	QMap<QString, QVariant> valueMap;

	//x轴坐标
	int value = ui.xLeftSpinBox->value();
	bllSettings.update("PlotConfig", "xLeftSpinBox", value);
	valueMap.insert("xLeftSpinBox", value);
	value = ui.xRightSpinBox->value();
	bllSettings.update("PlotConfig", "xRightSpinBox", value);
	valueMap.insert("xRightSpinBox", value);
	value = ui.xAutoCheckBox->isChecked();
	bllSettings.update("PlotConfig", "xAutoCheckBox", value);
	valueMap.insert("xAutoCheckBox", value);
	//y轴坐标
	value = ui.yDownSpinBox->value();
	bllSettings.update("PlotConfig", "yDownSpinBox", value);
	valueMap.insert("yDownSpinBox", value);
	value = ui.yTopSpinBox->value();
	bllSettings.update("PlotConfig", "yTopSpinBox", value);
	valueMap.insert("yTopSpinBox", value);
	value = ui.yAutoCheckBox->isChecked();
	bllSettings.update("PlotConfig", "yAutoCheckBox", value);
	valueMap.insert("yAutoCheckBox", value);


	//画布曲线颜色-散点图
	QPalette palette = ui.scatterColorBtn->palette();
	QColor backGround = palette.color(QPalette::Background);
	QString name = backGround.name();
	bllSettings.update("PlotConfig", "scatterColorBtn", name);
	valueMap.insert("scatterColorBtn", name);
	value = ui.scatterWideSpinBox->value();
	bllSettings.update("PlotConfig", "scatterWideSpinBox", value);
	valueMap.insert("scatterWideSpinBox", value);
	value = ui.scatterDefaultCheckBox->isChecked();
	bllSettings.update("PlotConfig", "scatterDefaultCheckBox", value);
	valueMap.insert("scatterDefaultCheckBox", value);



	emit scatterPlotConfigChange(valueMap);

}
/**
* @brief 初始直方图Plot默认参数
* @param valueMap
*/
void PlotConfig::initBarChartPlotSettings(QMap<QString, QVariant>& valueMap)
{
	//X轴坐标
	int value = 0;
	value = bllSettings.read("PlotConfig", "xLeftSpinBox_2").toInt();
	ui.xLeftSpinBox_2->setValue(value);
	valueMap.insert("xLeftSpinBox_2", value);

	value = bllSettings.read("PlotConfig", "xRightSpinBox_2").toInt();
	ui.xRightSpinBox_2->setValue(value);
	valueMap.insert("xRightSpinBox_2", value);

	value = bllSettings.read("PlotConfig", "xAutoCheckBox_2").toInt();
	ui.xAutoCheckBox_2->setChecked(value);//也会激活on_xAutoCheckBox_toggled函数
	valueMap.insert("xAutoCheckBox_2", value);

	//Y轴坐标
	value = bllSettings.read("PlotConfig", "yDownSpinBox_2").toInt();
	ui.yDownSpinBox_2->setValue(value);
	valueMap.insert("yDownSpinBox_2", value);

	value = bllSettings.read("PlotConfig", "yTopSpinBox_2").toInt();
	ui.yTopSpinBox_2->setValue(value);
	valueMap.insert("yTopSpinBox_2", value);
	value = bllSettings.read("PlotConfig", "yAutoCheckBox_2").toInt();
	ui.yAutoCheckBox_2->setChecked(value);//也会激活on_yAutoCheckBox_toggled函数
	valueMap.insert("yAutoCheckBox_2", value);


	//直方图粗细颜色
	QString colorName;
	colorName = bllSettings.read("PlotConfig", "barChatColorBtn").toString();
	setColorBtn(ui.barChatColorBtn, colorName);
	valueMap.insert("barChatColorBtn", value);

	value = bllSettings.read("PlotConfig", "barChatWideSpinBox").toInt();
	ui.barChatWideSpinBox->setValue(value);
	valueMap.insert("barChatWideSpinBox", value);

	value = bllSettings.read("PlotConfig", "barChartDefaultCheckBox").toInt();
	ui.barChartDefaultCheckBox->setChecked(value);//也会激活on_barChartDefaultCheckBox_toggled函数
	valueMap.insert("barChartDefaultCheckBox", value);

}
/**
* @brief 更新直方图画布默认参数
*/
void PlotConfig::updateBarChartPlotSettings()
{

	QMap<QString, QVariant> valueMap;
	//x轴坐标
	int value = ui.xLeftSpinBox_2->value();
	bllSettings.update("PlotConfig", "xLeftSpinBox_2", value);
	valueMap.insert("xLeftSpinBox_2", value);

	value = ui.xRightSpinBox_2->value();
	bllSettings.update("PlotConfig", "xRightSpinBox_2", value);
	valueMap.insert("xRightSpinBox_2", value);
	value = ui.xAutoCheckBox_2->isChecked();
	bllSettings.update("PlotConfig", "xAutoCheckBox_2", value);
	valueMap.insert("xAutoCheckBox_2", value);
	//y轴坐标
	value = ui.yDownSpinBox_2->value();
	bllSettings.update("PlotConfig", "yDownSpinBox_2", value);
	valueMap.insert("yDownSpinBox_2", value);
	value = ui.yTopSpinBox_2->value();
	bllSettings.update("PlotConfig", "yTopSpinBox_2", value);
	valueMap.insert("yTopSpinBox_2", value);
	value = ui.yAutoCheckBox_2->isChecked();
	bllSettings.update("PlotConfig", "yAutoCheckBox_2", value);
	valueMap.insert("yAutoCheckBox_2", value);

	//画布曲线颜色-直方图
	QPalette palette = ui.barChatColorBtn->palette();
	QColor backGround = palette.color(QPalette::Background);
	QString name = backGround.name();
	bllSettings.update("PlotConfig", "barChatColorBtn", name);
	valueMap.insert("barChatColorBtn", name);

	value = ui.barChatWideSpinBox->value();
	bllSettings.update("PlotConfig", "barChatWideSpinBox", value);
	valueMap.insert("barChatWideSpinBox", value);
	value = ui.barChartDefaultCheckBox->isChecked();
	bllSettings.update("PlotConfig", "barChartDefaultCheckBox", value);
	valueMap.insert("barChartDefaultCheckBox", value);

	emit barchartPlotConfigChange(valueMap);

}

/**
* @brief 初始Plot默认参数
* @param valueMap
*/
void PlotConfig::initPlotSettings(QMap<QString, QVariant>& valueMap)
{
	QString colorName;
	int value = 0;
	colorName = bllSettings.read("PlotConfig", "plotColorBtn").toString();
	//如果是未自定义，则显示默认颜色
	if (colorName == "#000000")
		on_defaultCheckBox_toggled(true);//当做选中默认checkbox
	setColorBtn(ui.plotColorBtn, colorName);
	valueMap.insert("plotColorBtn", value);

	value = bllSettings.read("PlotConfig", "defaultCheckBox").toInt();
	ui.defaultCheckBox->setChecked(value);//也会激活on_defaultCheckBox_toggled函数
	valueMap.insert("defaultCheckBox", value);
}

/**
* @brief 更新画布默认参数
*/
void PlotConfig::updatePlotSettings()
{
	QMap<QString, QVariant> valueMap;

	//画布曲线颜色
	QPalette palette = ui.plotColorBtn->palette();
	QColor backGround = palette.color(QPalette::Background);
	QString name = backGround.name();
	bllSettings.update("PlotConfig", "plotColorBtn", name);
	valueMap.insert("plotColorBtn", name);

	int value = ui.defaultCheckBox->isChecked();
	bllSettings.update("PlotConfig", "defaultCheckBox", value);
	valueMap.insert("defaultCheckBox", value);
	emit plotConfigChange(valueMap);

}


/**
* @brief 确认
*/
void PlotConfig::on_okBtnProperty_clicked()
{
	int pageIndex = ui.stackedWidgetProperty->currentIndex();
	switch (pageIndex)
	{
	//散点图设置
	case 0:
		updateScatterPlotSettings();//更新画布参数变化
		break;
	//直方图设置
	case 1:
		updateBarChartPlotSettings();
		break;
	//画布设置
	case 2:
		updatePlotSettings();
		break;
	default:
		;
	}
	
}
/**
* @brief 取消
*/
void PlotConfig::on_cancleBtnPropety_clicked()
{
	emit plotConfigClosed();
	this->close();
}


/**
* @brief 初始画布背景颜色
*/
void PlotConfig::on_plotColorBtn_clicked()
{
	setColorBtn(ui.plotColorBtn);
}
/**
* @brief  x轴坐标范围自动变化
*/
void PlotConfig::on_xAutoCheckBox_toggled(bool enable)
{
	if (enable)
	{
		ui.xLeftSpinBox->setEnabled(false);
		ui.xRightSpinBox->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.xLeftSpinBox->setEnabled(true);
		ui.xRightSpinBox->setEnabled(true);
	}
}
/**
* @brief  散点图y轴坐标范围自动变化
*/
void PlotConfig::on_yAutoCheckBox_toggled(bool enable)
{
	if (enable)
	{
		ui.yDownSpinBox->setEnabled(false);
		ui.yTopSpinBox->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.yDownSpinBox->setEnabled(true);
		ui.yTopSpinBox->setEnabled(true);
	}

}

/**
* @brief  直方图x轴坐标范围自动变化
*/
void PlotConfig::on_xAutoCheckBox_2_toggled(bool enable)
{
	if (enable)
	{
		ui.xLeftSpinBox_2->setEnabled(false);
		ui.xRightSpinBox_2->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.xLeftSpinBox_2->setEnabled(true);
		ui.xRightSpinBox_2->setEnabled(true);
	}
}
/**
* @brief  直方图y轴坐标范围自动变化
*/
void PlotConfig::on_yAutoCheckBox_2_toggled(bool enable)
{
	if (enable)
	{
		ui.yDownSpinBox_2->setEnabled(false);
		ui.yTopSpinBox_2->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.yDownSpinBox_2->setEnabled(true);
		ui.yTopSpinBox_2->setEnabled(true);
	}

}
/**
* @brief  直方图线条颜色粗细设置
*/
void PlotConfig::on_barChartDefaultCheckBox_toggled(bool enable)
{
	if (enable)
	{
		ui.barChatWideSpinBox->setValue(2);
		ui.barChatWideSpinBox->setEnabled(false);

		setColorBtn(ui.barChatColorBtn,"#325481");
		ui.barChatColorBtn->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.barChatWideSpinBox->setEnabled(true);
		ui.barChatColorBtn->setEnabled(true);
	}

}
/**
* @brief  散点图线条颜色粗细设置
*/
void PlotConfig::on_scatterDefaultCheckBox_toggled(bool enable)
{
	if (enable)
	{
		ui.scatterWideSpinBox->setValue(2);
		ui.scatterWideSpinBox->setEnabled(false);

		setColorBtn(ui.scatterColorBtn, "DarkBlue");
		ui.scatterColorBtn->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.scatterWideSpinBox->setEnabled(true);
		ui.scatterColorBtn->setEnabled(true);
	}

}
/**
* @brief  画布颜色设置
*/
void PlotConfig::on_defaultCheckBox_toggled(bool enable)
{
	if (enable)
	{
		setColorBtn(ui.plotColorBtn, "#FFFFFF");
		ui.plotColorBtn->setEnabled(false);
	}
	else
	{
		//值前面已经赋值
		ui.plotColorBtn->setEnabled(true);
	}

}
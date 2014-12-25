#include "ParamWidget.h"
#include <QPainter>
#include <Windows.h>
ParamWidget::ParamWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//初始化激光的通道默认数值
	ui.laserComboBox->addItem("FSC-H", (int)1);
	ui.laserComboBox->addItem("SSC-H", (int)2);
	ui.laserComboBox->addItem("FL1-H", (int)3);
	ui.laserComboBox->addItem("FL2-H", (int)4);
	ui.laserComboBox->addItem("FL3-H", (int)5);
	ui.laserComboBox->addItem("FL4-H", (int)6);
	ui.laserComboBox->addItem("FL5-H", (int)7);
	ui.laserComboBox->addItem("FL6-H", (int)8);
	ui.laserComboBox->setCurrentIndex(0);//默认通道1


	//初始化触发值通道默认数值
	ui.triggerComboBox->addItem("FSC-H", (int)1);
	ui.triggerComboBox->addItem("SSC-H", (int)2);
	ui.triggerComboBox->addItem("FL1-H", (int)3);
	ui.triggerComboBox->addItem("FL2-H", (int)4);
	ui.triggerComboBox->addItem("FL3-H", (int)5);
	ui.triggerComboBox->addItem("FL4-H", (int)6);
	ui.triggerComboBox->addItem("FL5-H", (int)7);
	ui.triggerComboBox->addItem("FL6-H", (int)8);
	ui.triggerComboBox->setCurrentIndex(0);//默认通道1

	//默认中等速度
	ui.midRadioButton->setChecked(true);
	ui.midRadioButton->clicked();

	initAcqParams();//初始化控制面板参数

}

ParamWidget::~ParamWidget()
{
	saveAcqParams();//关闭窗口保存控制面板参数
	closeFluid();//关闭鞘液和样品流
}
void ParamWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
/**
* @brief 设置激光强度
*/
void ParamWidget::on_setLaserBtn_clicked()
{
	int passage = ui.laserComboBox->currentData().toInt();
	int strength = ui.strengthSpin->value();
	VoLaser vo;
	vo.setCmd(1);
	vo.setLength(2);
	vo.setPassage(passage);
	vo.setStrength(strength);
	bllControl->setLaser(vo);


	//激光强度
	int value = ui.laserComboBox->currentIndex();
	bllSettings.update("ParamWidget", "laserComboBox", value);
	value = ui.strengthSpin->value();
	bllSettings.update("ParamWidget", "strengthSpin", value);
}
/**
* @brief 设置鞘液
*/
void ParamWidget::on_setFluidBtn_clicked()
{
	int velocity = ui.fluidSpin->value();
	VoFluid vo;
	vo.setCmd(2);
	vo.setLength(2);
	vo.setVelocity(velocity);
	
	if (bllControl->setFluid(vo))
	{
		QIcon icon;
		icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/started.png"), QSize(), QIcon::Normal, QIcon::Off);
		ui.setFluidBtn->setIcon(icon);
		ui.setFluidBtn->setIconSize(QSize(25, 25));
		ui.setFluidBtn->setAutoRaise(true);
	}


	//鞘液
	int value = ui.fluidSpin->value();
	bllSettings.update("ParamWidget", "fluidSpin", value);
}
/**
* @brief 设置鞘液停止
*/
void ParamWidget::on_setFluidStopBtn_clicked()
{
	VoFluid vo;
	vo.setCmd(2);
	vo.setLength(2);
	vo.setVelocity(0);
	if (bllControl->setFluid(vo))
	{
		QIcon icon;
		icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/start.png"), QSize(), QIcon::Normal, QIcon::Off);
		ui.setFluidBtn->setIcon(icon);
		ui.setFluidBtn->setIconSize(QSize(25, 25));
		ui.setFluidBtn->setAutoRaise(true);
	}
}
/**
* @brief 设置样品流
*/
void ParamWidget::on_setSampleBtn_clicked()
{
	int velocity = ui.sampleSpin->value();
	VoSample vo;
	vo.setCmd(3);
	vo.setLength(2);
	vo.setVelocity(velocity);
	if (bllControl->setSample(vo))
	{
		QIcon icon;
		icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/started.png"), QSize(), QIcon::Normal, QIcon::Off);
		ui.setSampleBtn->setIcon(icon);
		ui.setSampleBtn->setIconSize(QSize(25, 25));
		ui.setSampleBtn->setAutoRaise(true);
	}


	//样品流速
	int value = ui.sampleSpin->value();
	bllSettings.update("ParamWidget", "sampleSpin", value);
}
/**
* @brief 设置样品流停止
*/
void ParamWidget::on_setSampleStopBtn_clicked()
{
	VoSample vo;
	vo.setCmd(3);
	vo.setLength(2);
	vo.setVelocity(0);
	if (bllControl->setSample(vo))
	{
		QIcon icon;
		icon.addFile(QStringLiteral(":/MainWindow/Resources/Images/MainWindow/start.png"), QSize(), QIcon::Normal, QIcon::Off);
		ui.setSampleBtn->setIcon(icon);
		ui.setSampleBtn->setIconSize(QSize(25, 25));
		ui.setSampleBtn->setAutoRaise(true);
	}
}
/**
* @brief 设置通道偏压
*/
void ParamWidget::on_setChannelBiasBtn_clicked()
{

	int passage = 0;
	QList<int> voltageList;
	int FSC_voltage = ui.FSC_spinBox->value();
	voltageList.append(FSC_voltage);
	int SSC_voltage = ui.SSC_spinBox->value();
	voltageList.append(SSC_voltage);
	int FL1_voltage = ui.FL1_spinBox->value();
	voltageList.append(FL1_voltage);
	int FL2_voltage = ui.FL2_spinBox->value();
	voltageList.append(FL2_voltage);
	int FL3_voltage = ui.FL3_spinBox->value();
	voltageList.append(FL3_voltage);
	int FL4_voltage = ui.FL4_spinBox->value();
	voltageList.append(FL4_voltage);

	for (int i = 0; i < voltageList.size(); i++)
	{
		VoChannelBias vo;
		vo.setCmd(4);
		vo.setLength(2);
		vo.setChannel(i+1);//通道值1-8
		vo.setVoltage(voltageList.at(i));
		bllControl->setChannelBias(vo);
		Sleep(10);//防止过快
	}

	//通道偏压
	int value = ui.FSC_spinBox->value();
	bllSettings.update("ParamWidget", "FSC_spinBox", value);

	value = ui.SSC_spinBox->value();
	bllSettings.update("ParamWidget", "SSC_spinBox", value);

	value = ui.FL1_spinBox->value();
	bllSettings.update("ParamWidget", "FL1_spinBox", value);

	value = ui.FL2_spinBox->value();
	bllSettings.update("ParamWidget", "FL2_spinBox", value);

	value = ui.FL3_spinBox->value();
	bllSettings.update("ParamWidget", "FL3_spinBox", value);

	value = ui.FL4_spinBox->value();
	bllSettings.update("ParamWidget", "FL4_spinBox", value);


}

/**
* @brief 设置触发值
*/
void ParamWidget::on_setTriggerBtn_clicked()
{
	int trigger = ui.triggerSpin->value();
	int passage = ui.triggerComboBox->currentData().toInt();
	VoTrigger vo;
	vo.setCmd(7);
	vo.setLength(4);
	vo.setChannel1(0);//暂时不支持
	vo.setChannel2(passage);
	vo.setTriggerValue(trigger);
	bllControl->setTrigger(vo);


	//触发值
	int value = ui.triggerComboBox->currentIndex();
	bllSettings.update("ParamWidget", "triggerComboBox", value);
	value = ui.triggerSpin->value();
	bllSettings.update("ParamWidget", "triggerSpin", value);

}

/**
* @brief 设置样品流速-中档
*/
void ParamWidget::on_midRadioButton_clicked()
{
	ui.sampleSpin->setValue(800);
}

/**
* @brief 设置样品流速-高档
*/
void ParamWidget::on_hightRadioButton_clicked()
{

	ui.sampleSpin->setValue(3000);
}

/**
* @brief 设置样品流速-低档
*/
void ParamWidget::on_lowRadioButton_clicked()
{

	ui.sampleSpin->setValue(100);
}

void ParamWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
}

/**
* @brief 保存控制面板参数
*/
void ParamWidget::saveAcqParams()
{

	//触发值
	int value = ui.triggerComboBox->currentIndex();
	bllSettings.update("ParamWidget", "triggerComboBox", value);
	value = ui.triggerSpin->value();
	bllSettings.update("ParamWidget", "triggerSpin", value);

	//激光强度
	value = ui.laserComboBox->currentIndex();
	bllSettings.update("ParamWidget", "laserComboBox", value);
	value = ui.strengthSpin->value();
	bllSettings.update("ParamWidget", "strengthSpin", value);

	//通道偏压
	value = ui.FSC_spinBox->value();
	bllSettings.update("ParamWidget", "FSC_spinBox", value);

	value = ui.SSC_spinBox->value();
	bllSettings.update("ParamWidget", "SSC_spinBox", value);

	value = ui.FL1_spinBox->value();
	bllSettings.update("ParamWidget", "FL1_spinBox", value);

	value = ui.FL2_spinBox->value();
	bllSettings.update("ParamWidget", "FL2_spinBox", value);

	value = ui.FL3_spinBox->value();
	bllSettings.update("ParamWidget", "FL3_spinBox", value);

	value = ui.FL4_spinBox->value();
	bllSettings.update("ParamWidget", "FL4_spinBox", value);


	//鞘液
	value = ui.fluidSpin->value();
	bllSettings.update("ParamWidget", "fluidSpin", value);

	//样品流速
	value = ui.sampleSpin->value();
	bllSettings.update("ParamWidget", "sampleSpin", value);

}
/**
* @brief 初始化控制面板参数
*/
void ParamWidget::initAcqParams()
{
	//触发值
	int value = 0;
	value = bllSettings.read("ParamWidget", "triggerComboBox").toInt();
	if (value != -1)
		ui.triggerComboBox->setCurrentIndex(value);

	value = bllSettings.read("ParamWidget", "triggerSpin").toInt();
	if (value != -1)
		ui.triggerSpin->setValue(value);




	//激光强度
	value = bllSettings.read("ParamWidget", "laserComboBox").toInt();
	if (value != -1)
		ui.laserComboBox->setCurrentIndex(value);

	value = bllSettings.read("ParamWidget", "strengthSpin").toInt();
	if (value != -1)
		ui.strengthSpin->setValue(value);


	//通道偏压
	value = bllSettings.read("ParamWidget", "FSC_spinBox").toInt();
	if (value != -1)
		ui.FSC_spinBox->setValue(value);

	value = bllSettings.read("ParamWidget", "SSC_spinBox").toInt();
	if (value != -1)
		ui.SSC_spinBox->setValue(value);

	value = bllSettings.read("ParamWidget", "FL1_spinBox").toInt();
	if (value != -1)
		ui.FL1_spinBox->setValue(value);

	value = bllSettings.read("ParamWidget", "FL2_spinBox").toInt();
	if (value != -1)
		ui.FL2_spinBox->setValue(value);

	value = bllSettings.read("ParamWidget", "FL3_spinBox").toInt();
	if (value != -1)
		ui.FL3_spinBox->setValue(value);

	value = bllSettings.read("ParamWidget", "FL4_spinBox").toInt();
	if (value != -1)
		ui.FL4_spinBox->setValue(value);

	//鞘液
	value = bllSettings.read("ParamWidget", "fluidSpin").toInt();
	if (value != -1)
		ui.fluidSpin->setValue(value);

	//样品流速
	value = bllSettings.read("ParamWidget", "sampleSpin").toInt();
	if (value != -1)
		ui.sampleSpin->setValue(value);
}


/**
* @brief 保存控制面板参数
*/
void ParamWidget::closeFluid()
{
	on_setFluidStopBtn_clicked();//鞘液停止
	on_setSampleStopBtn_clicked();//样品流停止
}
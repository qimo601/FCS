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

}

ParamWidget::~ParamWidget()
{

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
	bllControl->setFluid(vo);
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
	bllControl->setSample(vo);
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
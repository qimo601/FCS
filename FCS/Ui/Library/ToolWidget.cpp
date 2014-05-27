#include "ToolWidget.h"
#include<QBitmap>
ToolWidget::ToolWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
// 	QPixmap acqPixmap(":/MainWindow/Resources/Images/MainWindow/acq.png");
// 	acqPixmap = acqPixmap.scaled(acqPixmap.size() / 2, Qt::IgnoreAspectRatio, Qt::FastTransformation);
// 	ui.acqBtn->setMask(acqPixmap.mask());
// 	QPixmap analyPixmap(":/MainWindow/Resources/Images/MainWindow/analy.png");
// 	analyPixmap = analyPixmap.scaled(analyPixmap.size() / 2, Qt::IgnoreAspectRatio, Qt::FastTransformation);
// 	ui.analyBtn->setMask(analyPixmap.mask());

	acqPixmap.load(":/MainWindow/Resources/Images/MainWindow/acq");
	analyPixmap.load(":/MainWindow/Resources/Images/MainWindow/analy");
	ui.acqBtn->setMask(acqPixmap.mask());
	ui.analyBtn->setMask(analyPixmap.mask());
 	//ui.acqBtn->setPicName(":/MainWindow/Resources/Images/MainWindow/acq");
 	//ui.analyBtn->setPicName(":/MainWindow/Resources/Images/MainWindow/analy");

	on_analyBtn_clicked();
}

ToolWidget::~ToolWidget()
{

}
//void ToolWidget::paintEvent(QPaintEvent*){
// 	QPainter painter(this);
// 	QPixmap pixmap;
// 	pixmap.load(":/MainWindow/Resources/Images/MainWindow/acq");
// 	painter.drawPixmap(0, 0, pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)); // ���Ʋ����򱳾�  
//}
void ToolWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);


	
	QPainter painter(this);
// 	painter.drawPixmap(ui.acqBtn->pos().x(), ui.acqBtn->pos().y(), ui.acqBtn->rect().width(), ui.acqBtn->rect().height(), acqPixmap);
// 	painter.drawPixmap(ui.analyBtn->pos().x()-20, ui.analyBtn->pos().y(), ui.analyBtn->rect().width(), ui.analyBtn->rect().height(), analyPixmap);

}
/**
* @brief �������ð�ťλ��
*/
void ToolWidget::resetGeometry(int x)
{
	
 	QRect rect = ui.analyBtn->geometry();
	//rect.setX(0);
 	//ui.analyBtn->setGeometry(rect);
}
/**
* @brief �ɼ���ť-ʾ�����ɼ�����
*/
void ToolWidget::on_acqBtn_clicked()
{
	ui.acqBtn->setStyleSheet(QLatin1String("QPushButton#acqBtn{border: 1px solid #D4D3CC;background-color:#D4D3CC;border-radius:0px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#acqBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.analyBtn->setStyleSheet(QLatin1String("QPushButton#analyBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#analyBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.fileBrowserBtn->setStyleSheet(QLatin1String("QPushButton#fileBrowserBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#fileBrowserBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	
	emit acqBtnClicked();
}
/**
* @brief ���ݷ����뱨�洰����ʾ
*/
void ToolWidget::on_analyBtn_clicked()
{
	ui.analyBtn->setStyleSheet(QLatin1String("QPushButton#analyBtn{border: 1px solid #D4D3CC;background-color:#D4D3CC;border-radius:0px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#analyBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.acqBtn->setStyleSheet(QLatin1String("QPushButton#acqBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#acqBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.fileBrowserBtn->setStyleSheet(QLatin1String("QPushButton#fileBrowserBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#fileBrowserBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	emit analyBtnClicked();
}
/**
* @brief �ļ����������
*/
void ToolWidget::on_fileBrowserBtn_clicked()
{
	ui.fileBrowserBtn->setStyleSheet(QLatin1String("QPushButton#fileBrowserBtn{border: 1px solid #D4D3CC;background-color:#D4D3CC;border-radius:0px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#fileBrowserBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.analyBtn->setStyleSheet(QLatin1String("QPushButton#analyBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#analyBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	ui.acqBtn->setStyleSheet(QLatin1String("QPushButton#acqBtn{border: 1px solid #AAAAAA;background-color:#AAAAAA;border-radius:2px;width: 40px;height:20px;padding:0 0px;} \n"
		"QPushButton#acqBtn:hover{ border: 1px solid #E3C46F; background-color:#FEF4BF;border-radius:2px; width:40px;height:20px; padding:0 0px;}"
		));
	
	emit fileBrowserBtnClicked();
}

void ToolWidget::resizeEvent(QResizeEvent * event)
{
	QSize size = event->size();
	int widgetHeight = size.rheight();
	int widgetWidth = size.rwidth();

	//ȷ��ÿ�α��Σ�analyBtn��ť������20
	ui.analyBtn->move(ui.analyBtn->pos().x() - 18, ui.analyBtn->pos().y());


}
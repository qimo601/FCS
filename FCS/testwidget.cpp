#include "testwidget.h"
#include <QBitmap>
#include <QMdiSubWindow>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include "Ui/Library/PlotWidget.h"
TestWidget::TestWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton123_clicked()));
	//timer->start(1000);

	QGraphicsScene* scene = new QGraphicsScene();
	PlotWidget* widget = new PlotWidget();

	scene->addWidget(widget);


	QLineF line(30,40,400,500);
	scene->addLine(line);
	ui.graphicsView->setScene(scene);

}

TestWidget::~TestWidget()
{

}
void TestWidget::on_pushButton1234_clicked()
{

	this->focusNextChild();

	//ui.pushButton_2->setStyleSheet("");
	/*QPalette pal = ui.pushButton_2->palette();
	pal.setColor(QPalette::Button, Qt::red);
	ui.pushButton_2->setAutoFillBackground(true);

	ui.pushButton_2->setPalette(pal);*/
	ui.toolButton->setAutoFillBackground(true);

	QRadialGradient gradient(50, 50, 50, 50, 50);
	gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
	gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

	QBrush brush(gradient);
	QPalette pal = ui.toolButton->palette();
	//pal.setBrush(QPalette::Button, brush);
	pal.setColor(QPalette::Button, Qt::red);
	ui.toolButton->setPalette(pal);

}
void TestWidget::resizeEvent(QResizeEvent * event)
{

	
}
/**
* @brief 鼠标滑动事件
*/
void TestWidget::mouseMoveEvent(QMouseEvent* event)
{
	
}
void TestWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
#ifndef BARSTRUCT_H
#define BARSTRUCT_H

#include <QObject>
#include <QColor>
#include <QPoint>
class BarStruct
{
	

public:
	BarStruct();
	BarStruct(double index,QString title, double value, QColor color, QPointF point);
	~BarStruct();
	BarStruct& operator = (const BarStruct&);
public:
	double m_index;
	QString m_title;//当前节点Bar标题
	double m_value; //当前节点Bar值
	QColor m_color;//当前节点颜色
	QPointF m_point;//当前条件范围
};

#endif // BARSTRUCT_H

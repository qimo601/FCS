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
	QString m_title;//��ǰ�ڵ�Bar����
	double m_value; //��ǰ�ڵ�Barֵ
	QColor m_color;//��ǰ�ڵ���ɫ
	QPointF m_point;//��ǰ������Χ
};

#endif // BARSTRUCT_H

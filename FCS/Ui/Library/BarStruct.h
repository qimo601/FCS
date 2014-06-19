#ifndef BARSTRUCT_H
#define BARSTRUCT_H

#include <QObject>
#include <QColor>
#include <QPoint>
class BarStruct
{
	

public:
	BarStruct(QString title, double value, QColor color, QPoint point);
	~BarStruct();
public:
	QString m_title;//��ǰ�ڵ�Bar����
	double m_value; //��ǰ�ڵ�Barֵ
	QColor m_color;//��ǰ�ڵ���ɫ
	QPoint m_point;//��ǰ������Χ
};

#endif // BARSTRUCT_H

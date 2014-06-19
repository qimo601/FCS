#include "BarStruct.h"

BarStruct::BarStruct(QString title, double value, QColor color, QPoint point)
{
	m_title = title;
	m_value = value;
	m_color = color;
	m_point = point;
}

BarStruct::~BarStruct()
{

}

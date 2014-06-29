#include "BarStruct.h"

BarStruct::BarStruct()
{
}
BarStruct::BarStruct(double index,QString title, double value, QColor color, QPointF point)
{
	m_index = index;
	m_title = title;
	m_value = value;
	m_color = color;
	m_point = point;
}

BarStruct::~BarStruct()
{

}

BarStruct& BarStruct::operator = (const BarStruct& vo)
{
	m_index = vo.m_index;
	m_title = vo.m_title;
	m_value = vo.m_value;
	m_color = vo.m_color;
	m_point = vo.m_point;
	
	return *this;

}

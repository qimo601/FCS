#include "GateStorage.h"

GateStorage::GateStorage(QObject *parent)
	: QObject(parent)
{
	m_parentWidget = 0;//���Ÿ��໭��

	m_plotWidget = 0;//���Ŷ�Ӧ���»���
	m_gatePointer = 0;//����ָ��

	m_gateColorName = "#000000";//Ĭ����ɫ

	

}

GateStorage::~GateStorage()
{

}

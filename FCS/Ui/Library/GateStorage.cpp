#include "GateStorage.h"

GateStorage::GateStorage(QObject *parent)
	: QObject(parent)
{
	m_parentWidget = 0;//设门父类画布

	m_plotWidget = 0;//设门对应的新画布
	m_gatePointer = 0;//设门指针
}

GateStorage::~GateStorage()
{

}

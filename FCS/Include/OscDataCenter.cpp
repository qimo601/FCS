#include "OscDataCenter.h"
#include <QVector>
OscDataCenter::OscDataCenter(QObject *parent)
	: QObject(parent)
{
}
OscDataCenter::~OscDataCenter()
{
}


QVector<double> OscDataCenter::oscXData;
QList<QVector<double>> OscDataCenter::oscYData;
QMutex OscDataCenter::mutex;
void OscDataCenter::setLock()
{
	mutex.lock();
}
void OscDataCenter::setUnlock()
{
	mutex.unlock();
}

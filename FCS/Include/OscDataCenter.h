/**
* ��    Ŀ:  FCS���
* �ļ�����:   OscDataCenter.h
* �ļ�·����  Include/OscDataCenter.h
* ժ    Ҫ:  ʾ����ȫ�����ݽӿ�
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��06��01��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef OSCDATACENTER_H
#define OSCDATACENTER_H

#include <QObject>
#include <QMutex>
class OscDataCenter : public QObject
{
	Q_OBJECT

public:
	OscDataCenter(QObject *parent=0);
	~OscDataCenter();

	//ʾ����X����ʾ����
	static QVector<double> oscXData;
	//ʾ����Y����ʾ����
	static QList<QVector<double>> oscYData;


	static QMutex mutex;
	static void setLock();
	static void setUnlock();



private:
	
	
};

#endif // OSCDATACENTER_H

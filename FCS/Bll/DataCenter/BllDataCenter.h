/**
* ��    Ŀ:  FCS���
* �ļ�����:  BllDataCenter.h
* �ļ�·���� DataCenter/BllDataCenter.h
* ժ    Ҫ:  ��������ҵ����
* ��    �ߣ� ���װ�
* ��    �ڣ� 2014��05��08��
* Copyright (c) 2014-2015, �п�Ժ����ҽ����ҽѧӰ���ҵ�����.All rights reserved.
* Version v1.0
*/
#ifndef BLLDATACENTER_H
#define BLLDATACENTER_H

#include <QObject>
#include "Include/Global.h"
#include "Include/ICellStaticData.h"
class BllDataCenter : public QObject
{
	Q_OBJECT

public:
	BllDataCenter(QObject *parent = 0);
	~BllDataCenter();

	/**
	* @brief ��ȡʾ������ʾ����
	*/
	void getOscData(QVector<double>& oscXData,QVector<double>& oscYData);
	/**
	* @brief ��ȡϸ����ʾ����
	* @param bool �Ƿ���վɵ�����
	*/
	void getCellData(bool clear = true);
	/**
	* @brief ��ȡϸ����ʾ����
	*/
	QVector<double>* getCellDataVector(int passage, int valuePos);

private:
	double stepValue;
	//ϸ�����ݽӿ�
	ICellStaticData* iCellStaticData;
};

#endif // BLLDATACENTER_H

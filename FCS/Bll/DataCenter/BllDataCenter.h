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
#include "Bll/DataCenter/ReadCellThread.h"
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
	* @param passage ͨ��
	* @param valuePos ֵλ��
	*/
	QVector<double>* getCellDataVector(int passage, int valuePos);
	/**
	* @brief ��ȡϸ����ʾ���ݽӿ�
	*/
	void getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList);
	/**
	* @brief ֱ��ͼ��ȡ���ݷ���
	*/
	void getCellDataVector(QList < QList < QVector<double>* > * >* origialDataList, QList < QList < QVector<double>* >*  >* logDataList, QList < QList < QVector<BarStruct>* >*  >* barStructList);
	/**
	* @brief ��ȡԴ����ϸ������
	*/
	double getAllEvents();
	/**
	* @brief ���Դ����ϸ������
	*/
	void clearAllEvents();
	/**
	* @brief ������Ļˢ��Ƶ�� freq * 8
	*/
	void setFreq(int freq);
	/**
	* @brief ������Ļ���Ƶ�� clear * 8
	*/
	void setClear(int clear);
private:
	double stepValue;
	//ϸ�����ݽӿ�
	ICellStaticData* iCellStaticData;

	char m_buffer[512];//һ��USBϸ�������ݰ�
	char m_bufferOSC[1024 * 16];//һ��ʾ����Ҫ��ʾ������

};

#endif // BLLDATACENTER_H

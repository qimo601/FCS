
#ifndef GATESTORAGE_H
#define GATESTORAGE_H

#include <QObject>

class GateStorage : public QObject
{
	Q_OBJECT

public:
	GateStorage(QObject *parent = 0);
	~GateStorage();
	enum GateType {
		//��������
		RECT = 0x0001,
		//ƽ��������
		PARALLEL = 0x0002,
		//��Բ
		ELLIPSE = 0x0003,
		//ʮ����
		CROSS = 0x0004,
		//�����
		POLYGON = 0x0005
	};
	//��ȡ�������ڸ��໭��ָ��
	QObject* getParentWidget() const
	{
		return m_parentWidget;
	}
	//�趨�������ڸ��໭������ָ��
	void setParentWidget(QObject* parentWidget)
	{
		m_parentWidget = parentWidget;
	}
	//��ȡ�»���ָ��
	QObject* getPlotWidget() const
	{
		return m_plotWidget;
	}
	//�趨�»���ָ��
	void setPlotWidget(QObject* plotWidget)
	{
		m_plotWidget = plotWidget;
	}

	//��ȡ����ָ��
	QObject* getGatePointer() const
	{
		return m_gatePointer;
	}
	//�趨����ָ��
	void setGatePointer(QObject* gatePointer)
	{
		m_gatePointer = gatePointer;
	}

	//��ȡ��������
	QString getGateName() const
	{
		return m_gateName;
	}
	//�趨��������
	void setGateName(QString gateName)
	{
		m_gateName = gateName;
	}
	//��ȡ������ɫ����
	QString getGateColorName() const
	{
		return m_gateColorName;
	}
	//�趨������ɫ����
	void setGateColorName(QString gateColorName)
	{
		m_gateColorName = gateColorName;
	}
	
	//��ȡ��������
	GateType getGateType() const
	{
		return m_gateType;
	}
	//�趨��������
	void setGateType(GateType gateType)
	{
		m_gateType = gateType;
	}
	//��ȡϸ������
	double getEvents() const
	{
		return m_events;
	}
	//�趨ϸ������
	void setEvents(double events)
	{
		m_events = events;
	}
	//��ȡ%Parent
	double getPercentageParent() const
	{
		return m_percentageParent;
	}
	//�趨%Parent
	void setPercentageParent(double percentageParent)
	{
		m_percentageParent = percentageParent;
	}
	//��ȡ%Total
	double getPercentageTotal() const
	{
		return m_percentageTotal;
	}
	//�趨%Total
	void setPercentageTotal(double percentageTotal)
	{
		m_percentageTotal = percentageTotal;
	}
	
	//��ȡƽ��ֵ
	QList<QList<double>> getAverageValue() const
	{
		return m_averageValueList;
	}
	//�趨ƽ��ֵ
	void setAverageValue(QList<QList<double>> averageValueList)
	{
		m_averageValueList = averageValueList;
	}
	//��ȡ�м�ֵ
	QList<QList<double>> getMidValue() const
	{
		return m_midValueList;
	}
	//�趨�м�ֵ
	void setMidValue(QList<QList<double>> midValueList)
	{
		m_midValueList = midValueList;
	}
	//��ȡ����ϵ��
	QList<QList<double>> getCvValue() const
	{
		return m_cvValueList;
	}
	//�趨����ϵ��
	void setCvValue(QList<QList<double>> cvValueList)
	{
		m_cvValueList = cvValueList;
	}
private:

	QObject* m_parentWidget;//���Ÿ��໭��

	QObject* m_plotWidget;//���Ŷ�Ӧ���»���
	QObject* m_gatePointer;//����ָ��

	QString m_gateName;//��������
	GateType m_gateType;//��������
	QString m_gateColorName;//���ŵ���ɫ
	double m_events;//ϸ������
	double m_percentageParent;//%Parent:��ǰ���ŵ�ϸ����Ŀ��ռ����İٷֱ�
	double m_percentageTotal;//%Total:��ǰ���ŵ�ϸ����Ŀ��ռԴ����ϸ�������İٷֱ�
	QList<QList<double>> m_averageValueList;
	double m_averageValue;//ƽ��ֵ��x1+x2+x3+...+xn��/n
	QList<QList<double>> m_midValueList;
	double m_midValue;//�м�ֵ��������м��ֵ��
	QList<QList<double>> m_cvValueList;
	double m_cvValue;//����ϵ�� CV(Coefficient of Variance):��׼�����ֵ�ı���
	/*
	CV=��/|��|������ ��=�̡�(xi-u)^2/(n-1)��u=(��xi)/n
	*/
};

#endif // GATESTORAGE_H

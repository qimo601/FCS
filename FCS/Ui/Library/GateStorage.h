
#ifndef GATESTORAGE_H
#define GATESTORAGE_H

#include <QObject>

class GateStorage : public QObject
{
	Q_OBJECT

public:
	GateStorage(QObject *parent);
	~GateStorage();
	//��ȡ����ָ��
	QObject* getPlotWidget() const
	{
		return m_plotWidget;
	}
	//�趨����ָ��
	void setTubeCurrent(QObject* plotWidget)
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
	//��ȡ��������
	QString getGateType() const
	{
		return m_gateType;
	}
	//�趨��������
	void setGateType(QString gateType)
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
	double getAverageValue() const
	{
		return m_averageValue;
	}
	//�趨ƽ��ֵ
	void setAverageValue(double averageValue)
	{
		m_averageValue = averageValue;
	}
	//��ȡ�м�ֵ
	double getMidValue() const
	{
		return m_midValue;
	}
	//�趨�м�ֵ
	void setMidValue(double midValue)
	{
		m_midValue = midValue;
	}
	//��ȡ����ϵ��
	double getCvValue() const
	{
		return m_cvValue;
	}
	//�趨����ϵ��
	void setCvValue(double cvValue)
	{
		m_cvValue = cvValue;
	}
private:
	QObject* m_plotWidget;//����ָ��
	QObject* m_gatePointer;//����ָ��
	QString m_gateName;//��������
	QString m_gateType;//��������
	double m_events;//ϸ������
	double m_percentageParent;//%Parent:��ǰ���ŵ�ϸ����Ŀ��ռ����İٷֱ�
	double m_percentageTotal;//%Total:��ǰ���ŵ�ϸ����Ŀ��ռԴ����ϸ�������İٷֱ�
	double m_averageValue;//ƽ��ֵ��x1+x2+x3+...+xn��/n
	double m_midValue;//�м�ֵ��������м��ֵ��
	double m_cvValue;//����ϵ�� CV(Coefficient of Variance):��׼�����ֵ�ı���
	/*
	CV=��/|��|������ ��=�̡�(xi-u)^2/(n-1)��u=(��xi)/n
	*/
};

#endif // GATESTORAGE_H

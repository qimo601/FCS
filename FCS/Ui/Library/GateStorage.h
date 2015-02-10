
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
		//矩形设门
		RECT = 0x0001,
		//平行线设门
		PARALLEL = 0x0002,
		//椭圆
		ELLIPSE = 0x0003,
		//十字线
		CROSS = 0x0004,
		//多边形
		POLYGON = 0x0005
	};
	//获取设门所在父类画布指针
	QObject* getParentWidget() const
	{
		return m_parentWidget;
	}
	//设定设门所在父类画布画布指针
	void setParentWidget(QObject* parentWidget)
	{
		m_parentWidget = parentWidget;
	}
	//获取新画布指针
	QObject* getPlotWidget() const
	{
		return m_plotWidget;
	}
	//设定新画布指针
	void setPlotWidget(QObject* plotWidget)
	{
		m_plotWidget = plotWidget;
	}

	//获取设门指针
	QObject* getGatePointer() const
	{
		return m_gatePointer;
	}
	//设定设门指针
	void setGatePointer(QObject* gatePointer)
	{
		m_gatePointer = gatePointer;
	}

	//获取设门名称
	QString getGateName() const
	{
		return m_gateName;
	}
	//设定设门名称
	void setGateName(QString gateName)
	{
		m_gateName = gateName;
	}
	//获取设门颜色名字
	QString getGateColorName() const
	{
		return m_gateColorName;
	}
	//设定设门颜色名字
	void setGateColorName(QString gateColorName)
	{
		m_gateColorName = gateColorName;
	}
	
	//获取设门类型
	GateType getGateType() const
	{
		return m_gateType;
	}
	//设定设门类型
	void setGateType(GateType gateType)
	{
		m_gateType = gateType;
	}
	//获取细胞个数
	double getEvents() const
	{
		return m_events;
	}
	//设定细胞个数
	void setEvents(double events)
	{
		m_events = events;
	}
	//获取%Parent
	double getPercentageParent() const
	{
		return m_percentageParent;
	}
	//设定%Parent
	void setPercentageParent(double percentageParent)
	{
		m_percentageParent = percentageParent;
	}
	//获取%Total
	double getPercentageTotal() const
	{
		return m_percentageTotal;
	}
	//设定%Total
	void setPercentageTotal(double percentageTotal)
	{
		m_percentageTotal = percentageTotal;
	}
	
	//获取平均值
	QList<QList<double>> getAverageValue() const
	{
		return m_averageValueList;
	}
	//设定平均值
	void setAverageValue(QList<QList<double>> averageValueList)
	{
		m_averageValueList = averageValueList;
	}
	//获取中间值
	QList<QList<double>> getMidValue() const
	{
		return m_midValueList;
	}
	//设定中间值
	void setMidValue(QList<QList<double>> midValueList)
	{
		m_midValueList = midValueList;
	}
	//获取变异系数
	QList<QList<double>> getCvValue() const
	{
		return m_cvValueList;
	}
	//设定变异系数
	void setCvValue(QList<QList<double>> cvValueList)
	{
		m_cvValueList = cvValueList;
	}
private:

	QObject* m_parentWidget;//设门父类画布

	QObject* m_plotWidget;//设门对应的新画布
	QObject* m_gatePointer;//设门指针

	QString m_gateName;//设门名称
	GateType m_gateType;//设门类型
	QString m_gateColorName;//设门的颜色
	double m_events;//细胞个数
	double m_percentageParent;//%Parent:当前设门的细胞数目，占父类的百分比
	double m_percentageTotal;//%Total:当前设门的细胞数目，占源数据细胞总数的百分比
	QList<QList<double>> m_averageValueList;
	double m_averageValue;//平均值（x1+x2+x3+...+xn）/n
	QList<QList<double>> m_midValueList;
	double m_midValue;//中间值（排序后，中间的值）
	QList<QList<double>> m_cvValueList;
	double m_cvValue;//变异系数 CV(Coefficient of Variance):标准差与均值的比率
	/*
	CV=σ/|μ|，其中 σ=√∑(xi-u)^2/(n-1)，u=(∑xi)/n
	*/
};

#endif // GATESTORAGE_H

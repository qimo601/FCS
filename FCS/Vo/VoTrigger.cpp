#include "VoTrigger.h"

VoTrigger::VoTrigger(QObject *parent)
: VoCmd(parent)
{

}

VoTrigger::~VoTrigger()
{

}
VoTrigger& VoTrigger::operator = (const VoTrigger& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	m_channel1 = vo.getChannel1();
	m_channel2 = vo.getChannel2();
	m_triggerValue = vo.getTriggerValue();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoTrigger& vo)
{
	//����
	int mCmd;
	//��������
	int mLength;
	//ͨ��1����
	int mChannel1;
	//ͨ��2����
	int mChannel2;
	//����ֵ����
	int mTriggerValue;


	in >> mCmd >> mLength >> mChannel1 >> mChannel2 >> mTriggerValue;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	vo.setChannel1(mChannel1);
	vo.setChannel2(mChannel2);
	vo.setTriggerValue(mTriggerValue);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoTrigger& vo)
{
	out << vo.getCmd() << vo.getLength() << vo.getChannel1() << vo.getChannel2() << vo.getTriggerValue();
	return out;
}
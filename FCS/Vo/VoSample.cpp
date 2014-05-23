#include "VoSample.h"

VoSample::VoSample(QObject *parent)
: VoCmd(parent)
{

}

VoSample::~VoSample()
{

}
VoSample& VoSample::operator = (const VoSample& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	m_velocity = vo.getVelocity();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoSample& vo)
{
	//����
	int mCmd;
	//��������
	int mLength;
	//���ٲ���
	int mVelocity;


	in >> mCmd >> mLength >> mVelocity;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	vo.setVelocity(mVelocity);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoSample& vo)
{
	out << vo.getCmd() << vo.getLength() << vo.getVelocity();
	return out;
}
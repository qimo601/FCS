#include "VoFluid.h"

VoFluid::VoFluid(QObject *parent)
	: VoCmd(parent)
{

}

VoFluid::~VoFluid()
{

}
VoFluid& VoFluid::operator = (const VoFluid& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	m_velocity = vo.getVelocity();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoFluid& vo)
{
	//命令
	int mCmd;
	//参数长度
	int mLength;
	//流速参数
	int mVelocity;


	in >> mCmd >> mLength >> mVelocity;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	vo.setVelocity(mVelocity);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoFluid& vo)
{
	out << vo.getCmd() << vo.getLength() << vo.getVelocity();
	return out;
}

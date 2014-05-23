#include "VoChannelBias.h"

VoChannelBias::VoChannelBias(QObject *parent)
: VoCmd(parent)
{

}

VoChannelBias::~VoChannelBias()
{

}
VoChannelBias& VoChannelBias::operator = (const VoChannelBias& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	m_channel = vo.getChannel();
	m_voltage = vo.getVoltage();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoChannelBias& vo)
{
	//命令
	int mCmd;
	//参数长度
	int mLength;
	//通道
	int mChannel;
	//通道电压
	int mVoltage;


	in >> mCmd >> mLength >> mChannel >> mVoltage;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	vo.setChannel(mChannel);
	vo.setVoltage(mVoltage);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoChannelBias& vo)
{
	out << vo.getCmd() << vo.getLength() << vo.getChannel() << vo.getVoltage();
	return out;
}
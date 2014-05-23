#include "VoCmd.h"

VoCmd::VoCmd(QObject *parent)
	: QObject(parent)
{

}

VoCmd::~VoCmd()
{

}
VoCmd& VoCmd::operator = (const VoCmd& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoCmd& vo)
{
	//命令
	int mCmd;
	//参数长度
	int mLength;


	in >> mCmd >> mLength;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoCmd& vo)
{
	out << vo.getCmd() << vo.getLength();
	return out;
}

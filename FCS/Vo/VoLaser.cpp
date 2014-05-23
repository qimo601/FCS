#include "VoLaser.h"

VoLaser::VoLaser(QObject *parent)
: VoCmd(parent)
{

}

VoLaser::~VoLaser()
{

}
VoLaser& VoLaser::operator = (const VoLaser& vo)
{
	m_cmd = vo.getCmd();
	m_length = vo.getLength();
	m_passage = vo.getPassage();
	m_strength = vo.getStrength();
	return *this;
}


QDataStream& operator>>(QDataStream& in, VoLaser& vo)
{
	//����
	int mCmd;
	//��������
	int mLength;
	//ͨ������
	int mPassage;
	//ǿ�Ȳ���
	int mStrength;


	in >> mCmd >> mLength >> mPassage >> mStrength;
	vo.setCmd(mCmd);
	vo.setLength(mLength);
	vo.setPassage(mPassage);
	vo.setStrength(mStrength);
	return in;
}
QDataStream& operator<<(QDataStream& out, const VoLaser& vo)
{
	out << vo.getCmd() << vo.getLength() << vo.getPassage() << vo.getStrength();
	return out;
}

#ifndef TCPPACKETPROCESSOR_H
#define TCPPACKETPROCESSOR_H

#include <QString>
#include "TcpDataProcessor.h"

#pragma pack(push,1)

///�����ͷ
typedef struct 
{
	///���峤��
	int nLen;
}PacketHead;

///�������۶��󣺰�ͷ+����
typedef struct 
{
	PacketHead head;
	char* body;
}Packet;

typedef struct  
{
	int number;
	char* data;
}packedData;

#pragma pack(pop)

class TcpPacketProcessor
{
public:
	TcpPacketProcessor();
	~TcpPacketProcessor();

	TcpDataProcessor m_Buffer;

	///���
	packedData packData(char* data,int nLen);
	///�����յ������ݷ��ڻ������󣬽��
	QString unpackData(char * data,int nLen);
};

#endif  //TCPPACKETPROCESSOR_H
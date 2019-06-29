#include "TcpPacketProcessor.h"

TcpPacketProcessor::TcpPacketProcessor()
{

}

TcpPacketProcessor::~TcpPacketProcessor()
{

}

packedData TcpPacketProcessor::packData(char* data,int nLen)
{
	Packet p;
	int headLen = sizeof(PacketHead);         //��ͷ��С
	p.head.nLen = nLen;                       //�����С
	char *buf = new char[headLen + nLen];
	memcpy(buf, &p.head, headLen);            //��ͷ
	memcpy(buf + headLen, data, 51);        //����
	
	packedData returndata;
	returndata.data = buf;
	returndata.number = headLen+nLen;

	return returndata;
}

//���
//data: Ҫ���͵�����
//nLen: Ҫ�������ݵĳ���
QString TcpPacketProcessor::unpackData(char *data, int nLen)
{
	m_Buffer.addMsg(data, nLen);              //������ݵ�������
	int totalLen = m_Buffer.getDataLen();  //�����������ݴ�С
	int headLen = sizeof(PacketHead);         //��ͷ��С
	while(totalLen > 0)
	{
		//������ͷ��������
		if(totalLen < headLen)
		{
			break;
		}

		Packet pack;                      //���յ��İ�
		memcpy(&pack.head, m_Buffer.m_pBuffer, headLen);   //��ͷ
		int bodyLen = pack.head.nLen;     //�����С
		int packLen = headLen + bodyLen;  //һ�����ݴ�С
		if(totalLen < packLen)            //����һ�����ݣ��ȹ����ٽ���
		{
			break;
		}

		//�����㹻��
		pack.body = new char[bodyLen];
		memcpy(pack.body, m_Buffer.m_pBuffer + headLen, bodyLen);  //����

		m_Buffer.poll(packLen);  //�Ƴ��������е�һ�����ݰ�
		totalLen -= (packLen);

		QString recData = QString(QLatin1String(pack.body));
		return recData;
	}
}
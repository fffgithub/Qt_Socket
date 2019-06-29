#ifndef TCPDATAPROCESSOR_H
#define TCPDATAPROCESSOR_H

//��ʼ��������С
#define BUFFER_SIZE 1024

#include <string.h>

class TcpDataProcessor
{
public:
	TcpDataProcessor();
	~TcpDataProcessor();

	///������
	char *m_pBuffer;
	///��������С
	int m_nBufferSize;
	///��������ǰ���ݴ�С
	int m_nOffset;

	///��ȡ��ǰ���������ݴ�С
	int getDataLen();
	///������������С
	bool reBufferSize(int nLen);
	///�����Ϣ��������
	bool addMsg(char *pBuf,int nLen);
	///��������λ
	void resetBuffer();
	///�Ƴ��������ײ��ĵ�һ�����ݰ�
	void poll(int nLen);
};
#endif  //TCPDATAPROCESSOR_H
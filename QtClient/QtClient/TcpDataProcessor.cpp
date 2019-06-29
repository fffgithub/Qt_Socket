#include "TcpDataProcessor.h"

TcpDataProcessor::TcpDataProcessor()
{
	m_nBufferSize = BUFFER_SIZE;  
	m_nOffset = 0;      
	m_pBuffer = new char[m_nBufferSize];     
	memset(m_pBuffer, 0, sizeof(m_pBuffer)); 
}

TcpDataProcessor::~TcpDataProcessor()
{

}

int TcpDataProcessor::getDataLen()
{
	return this->m_nOffset;
}

bool TcpDataProcessor::reBufferSize(int nLen)
{
	//����ԭ��������ַ
	char *oBuffer = m_pBuffer;  
	//try
	{
		//��֤��С��С
		nLen = nLen < 64 ? 64: nLen;  
		while(m_nBufferSize < nLen)
		{
			m_nBufferSize *= 2;
		}
		//�����»�����
		m_pBuffer = new char[m_nBufferSize]; 
		memset(m_pBuffer, 0, sizeof(m_pBuffer));
		//��ԭ�������е����ݿ������»�����
		memcpy(m_pBuffer, oBuffer, m_nOffset); 
		//�ͷ�ԭ������
		delete []oBuffer;  
	}
	/*catch(QException e)
	{
		return false;
	}*/
	return true;
}

//�򻺳����������Ϣ
/*
* pBuf��Ҫ��ӵ�����
* nLen�����ݳ���
* �ɹ�����true��ʧ�ܷ���false
*/
bool TcpDataProcessor::addMsg(char *pBuf, int nLen)
{
	//try
	{
		if(m_nOffset + nLen > m_nBufferSize)        //��������С�����µ������С
			reBufferSize(m_nOffset + nLen);
		memcpy(m_pBuffer + m_nOffset, pBuf, nLen); //�������ݿ�����������β
		m_nOffset += nLen;  //�޸�����ƫ��
	}
	/*catch(QException e)
	{
		return false;
	}*/
	return true;
}

//��������λ
void TcpDataProcessor::resetBuffer()
{
	if(m_nOffset > 0)
	{
		memset(m_pBuffer, 0, sizeof(m_pBuffer));
		m_nOffset = 0;
	}
}

//�Ƴ��������ײ���һ�����ݰ�
//nLen��һ�����ݰ��Ĵ�С
void TcpDataProcessor::poll(int nLen)
{
	if(m_nOffset == 0 || m_pBuffer == NULL)
		return;

	if(m_nOffset >= nLen)
	{
		memcpy(m_pBuffer, m_pBuffer + nLen, m_nOffset - nLen);
		m_nOffset -= nLen;
	}
}
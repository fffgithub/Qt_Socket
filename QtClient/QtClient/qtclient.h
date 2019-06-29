#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QtGui/QWidget>
#include "ui_qtclient.h"
#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>

class QtClient : public QWidget
{
	Q_OBJECT

public:
	QtClient(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtClient();

	void initTCP();
	void newConnect();

	private slots:
		////���ӷ�����
		void connectServer();
		////��������Ͽ�����
		void disconnectServer();
		////���շ��������͵�����
		void receiveData();	
		////���������������
		void sendData();

		////����ļ�
		void selectFile();
		////�����ļ�
		void sendFile();
		////�����ļ����ͽ���
		void updateFileProgress(qint64);
		////�����ļ����ս���
		void updateFileProgress();

private:
	Ui::QtClientClass ui;
	QTcpSocket *tcpSocket;
	QTcpSocket *fileSocket;

	///�ļ�����
	QFile *localFile;
	///�ļ���С
	qint64 totalBytes;      //�ļ����ֽ���
	qint64 bytesWritten;    //�ѷ��͵��ֽ���
	qint64 bytestoWrite;    //��δ���͵��ֽ���
	qint64 filenameSize;    //�ļ����ֵ��ֽ���
	qint64 bytesReceived;   //���յ��ֽ���
	///ÿ�η������ݴ�С
	qint64 perDataSize;
	QString filename;
	///���ݻ�����
	QByteArray inBlock;
	QByteArray outBlock;

	////ϵͳʱ��
	QDateTime current_date_time;
	QString str_date_time;
};

#endif // QTCLIENT_H

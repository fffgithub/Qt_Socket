#ifndef QTSERVER_H
#define QTSERVER_H

#include <QtGui/QWidget>
#include "ui_qtserver.h"

#include <QtNetwork>
#include <QAbstractSocket>
#include<QTcpServer>  
#include<QTcpSocket> 
#include <QDateTime>
#include <QDataStream>

#include <QFile>
#include <QFileDialog>

class QtServer : public QWidget
{
	Q_OBJECT

public:
	QtServer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtServer();

	QTcpServer *server;
	QTcpSocket *socket;
	QTcpServer *fileserver;
	QTcpSocket *filesocket;

private slots:  
	void sendMessage(); 
	void acceptConnection();
	////���տͻ��˷��͵�����
	void receiveData();

	void acceptFileConnection();
	void updateFileProgress();
	void displayError(QAbstractSocket::SocketError socketError);

	///ѡ���͵��ļ�
	void selectFile();
	void sendFile();
	////�����ļ����ͽ���
	void updateFileProgress(qint64);

private:
	Ui::QtServerClass ui;

	////�����ļ���ر���
	qint64 totalBytes;
	qint64 bytesReceived;
	qint64 bytestoWrite;
	qint64 bytesWritten;
	qint64 filenameSize;
	QString filename;
	///ÿ�η������ݴ�С
	qint64 perDataSize;
	QFile *localFile;
	////���ػ�����
	QByteArray inBlock;
	QByteArray outBlock;

	////ϵͳʱ��
	QDateTime current_date_time;
	QString str_date_time;
};

#endif // QTSERVER_H

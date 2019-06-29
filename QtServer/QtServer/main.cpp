#include "qtserver.h"
#include <QtGui/QApplication>
#include <QTextCodec> 

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("System");

	QTextCodec::setCodecForTr(codec);

	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QtServer w;
	w.show();
	return a.exec();
}

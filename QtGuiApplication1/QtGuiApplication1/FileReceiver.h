#pragma once
#include "QtGuiApplication1.h"
#include <QtCore/QThread>
#include <QtCore/QThreadPool>
#include <QtCore/QRunnable>
#include<WinSock2.h>
#include<Ws2tcpip.h>
#include<fstream>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
Q_DECLARE_METATYPE(SOCKET);
class Listener :public QThread
{
	Q_OBJECT
public:
	void run();
signals:
	void IncommingFile(SOCKET socket);
};

class FilesReceiver :public QObject
{
	Q_OBJECT
public:
	QString saveFlod;
public slots:
	void BeginListening();
	void StopListening();
	void process_Finished(unsigned short id, bool success, QString filePath);
	void process_Begin(QString filePath);
	void ReceiveSingleFile(SOCKET socket);
	void StopReceiving();
	void updateRecvFloder(QString floder);
	void BeginReceiving();
private:
	Listener* listener = new Listener;
	QThreadPool threadpool;
	unsigned short recvCount = 0;
signals:
	void BeginRecvSingleFile(QString filePath);
	void ReceiveFinished(unsigned short id, QString msg);
};

class SingleFileReceiver :public QObject, public QRunnable
{
	Q_OBJECT
public:
	unsigned short seqID;
	static bool stop;
	string saveFlod;
	void run();
	SOCKET socket;
signals:
	void finished(unsigned short id, bool success, QString msg);
	void begin(QString filePath);
};
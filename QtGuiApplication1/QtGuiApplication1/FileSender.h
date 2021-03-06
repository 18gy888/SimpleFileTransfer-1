#pragma once
#include <QtCore/QThread>
#include <QtCore/qthreadpool.h>
#include <string>
#include <QtCore/QRunnable>
#include<WinSock2.h>
#include<Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
class FilesSender :public QObject
{
	Q_OBJECT
public slots:
	void BeginSending(QString basepath, QStringList filename, QString IPaddress);
	void StopSending();
	void process_begin(unsigned short id);
	void process_process(unsigned short id, int value);
	void process_complete(unsigned short id, bool success, QString msg);
private:
	QThreadPool sthreadpool;
signals:
	void rpt_process(unsigned short id, QString msg);
};

class SingleFileSender :public QObject, public QRunnable
{
	Q_OBJECT
public:
	static bool stop;
	string ipAddress;
	string port;
	string fileName;
	string floderName;
	unsigned short seqID;
public:
	void run();
signals:
	void begin(unsigned short id);
	void process(unsigned short id, int value);
	void complete(unsigned short id, bool success, QString msg);
};

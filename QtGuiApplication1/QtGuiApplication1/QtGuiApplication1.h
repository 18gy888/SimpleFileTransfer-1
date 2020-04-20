#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include <Qtcore/qthread.h>
#include <Qtcore/QList>
#include <QtWidgets/qfiledialog.h>
#include "md5.h"
using namespace std;

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget* parent = Q_NULLPTR);
	~QtGuiApplication1();
	void CloseWindows();
private:
	QStringList getFiles(QString path, QString attachPath = ".");
	Ui::QtGuiApplication1Class ui;
	QThread receiveFiles;
	QThread sendFiles;
	bool recvState = true;
public slots:
	void ChangeRecvState();
	void showFileList();
	void ShowSendingMsg(unsigned short id, QString msg);
	void ShowRecvingMsg(QString filePath);
	void SendFiles();
	void ShowRecvingMsgById(unsigned short id, QString msg);
	void selectRecvFloder();
	void clearRecvTable();
	void InputIP();
signals:
	void BeginSending(QString basepath, QStringList filename, QString IPaddress);
	void updateRecvFloder(QString floder);
	void StopRecv();
	void BeginRecv();
};

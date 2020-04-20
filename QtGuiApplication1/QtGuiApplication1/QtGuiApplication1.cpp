#include "QtGuiApplication1.h"
#include "FileReceiver.h"
#include "FileSender.h"
#include<WinSock2.h>
#include<Ws2tcpip.h>
#include<qtextcodec.h>
#include <QMessageBox>
#include <QDir>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
QtGuiApplication1::QtGuiApplication1(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QRegExp regExp("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}:\\d{1,5}");
	ui.lineEdit->setValidator(new QRegExpValidator(regExp, this));

	FilesReceiver* fr = new FilesReceiver;
	FilesSender* fs = new FilesSender;
	fr->moveToThread(&receiveFiles);
	fr->BeginListening();
	fs->moveToThread(&sendFiles);

	connect(ui.pushButton, &QPushButton::clicked, this, &QtGuiApplication1::clearRecvTable);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &QtGuiApplication1::ChangeRecvState);
	connect(this, &QtGuiApplication1::StopRecv, fr, &FilesReceiver::StopReceiving);
	connect(this, &QtGuiApplication1::BeginRecv, fr, &FilesReceiver::BeginReceiving);
	//connect(ui.pushButton_2, &QPushButton::clicked, fr, &FilesReceiver::StopListening);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &QtGuiApplication1::SendFiles);
	connect(this, &QtGuiApplication1::BeginSending, fs, &FilesSender::BeginSending);
	connect(this, &QtGuiApplication1::updateRecvFloder, fr, &FilesReceiver::updateRecvFloder);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &QtGuiApplication1::showFileList);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &QtGuiApplication1::selectRecvFloder);
	connect(fs, &FilesSender::rpt_process, this, &QtGuiApplication1::ShowSendingMsg);
	//connect(&receiveFiles, &QThread::started, this, &QtGuiApplication1::ShowMsg);
	connect(fr, &FilesReceiver::BeginRecvSingleFile, this, &QtGuiApplication1::ShowRecvingMsg);
	connect(fr, &FilesReceiver::ReceiveFinished, this, &QtGuiApplication1::ShowRecvingMsgById);
	sendFiles.start();
	receiveFiles.start();
}

QtGuiApplication1::~QtGuiApplication1()
{
	sendFiles.quit();
	receiveFiles.quit();
	sendFiles.wait();
	receiveFiles.wait();
}

void QtGuiApplication1::CloseWindows()
{

	this->close();
}

QStringList QtGuiApplication1::getFiles(QString path, QString attachPath)
{
	QDir dir(path + attachPath);
	QStringList fileList = dir.entryList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QStringList folderList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
	QStringList returnList;
	for each (QString filename in fileList)
	{
		returnList << attachPath + '/' + filename;
	}
	for (int i = 0; i != folderList.size(); i++)
	{
		QStringList childFileList = getFiles(path, attachPath + '/' + folderList.at(i));
		returnList.append(childFileList);
	}

	return returnList;
}

void QtGuiApplication1::showFileList()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, "choose src Directory", "/");
	if (dirPath == "")return;
	ui.lineEdit_2->setText(QDir::toNativeSeparators(dirPath));
	QStringList fileList = getFiles(dirPath);
	ui.tableWidget->setRowCount(fileList.size());
	for (int i = 0; i < fileList.size(); i++)
	{
		QString path = fileList[i];
		QTableWidgetItem* item = new QTableWidgetItem(path);
		ui.tableWidget->setItem(i, 0, item);
	}
	//ui.tableWidget->update();
}

void QtGuiApplication1::ShowSendingMsg(unsigned short id, QString msg)
{
	ui.tableWidget->setItem(id, 1, new QTableWidgetItem(msg));
}

void QtGuiApplication1::ShowRecvingMsg(QString filePath)
{
	int count = ui.tableWidget_2->rowCount();
	ui.tableWidget_2->setRowCount(count + 1);
	ui.tableWidget_2->setItem(count, 0, new QTableWidgetItem(filePath));
	ui.tableWidget_2->setItem(count, 1, new QTableWidgetItem(QString::fromLocal8Bit("正在接收")));
}

void QtGuiApplication1::SendFiles()
{
	QStringList fileList;
	for (int i = 0; i < ui.tableWidget->rowCount(); ++i)
	{
		fileList << QDir::toNativeSeparators(ui.tableWidget->item(i, 0)->text());
	}
	emit BeginSending(ui.lineEdit_2->text(), fileList, ui.lineEdit->text());
}

void QtGuiApplication1::ShowRecvingMsgById(unsigned short id, QString msg)
{
	ui.tableWidget_2->setItem(id, 1, new QTableWidgetItem(msg));
}

void QtGuiApplication1::selectRecvFloder()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, "choose src Directory", "/");
	if (dirPath == "")return;
	ui.lineEdit_3->setText(QDir::toNativeSeparators(dirPath));
	emit updateRecvFloder(QDir::toNativeSeparators(dirPath) + '\\');
}

void QtGuiApplication1::clearRecvTable()
{
	ui.tableWidget_2->clear();
}

void QtGuiApplication1::ChangeRecvState()
{
	if (recvState)
	{
		emit StopRecv();
		ui.pushButton_2->setText(QString::fromLocal8Bit("开始接收"));
	}
	else
	{
		emit BeginRecv();
		ui.pushButton_2->setText(QString::fromLocal8Bit("停止接收"));
	}
	recvState = !recvState;
}

void QtGuiApplication1::InputIP()
{
	//ui.lineEdit->
}


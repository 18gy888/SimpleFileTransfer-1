#include "FileSender.h"
#include <fstream>
#include "md5.h"
using namespace std;

void FilesSender::BeginSending(QString basepath, QStringList filename)
{
	sthreadpool.setMaxThreadCount(4);
	for (int i = 0; i < filename.size(); i++)
	{
		SingleFileSender* fs = new SingleFileSender;
		fs->seqID = i;
		fs->setAutoDelete(true);
		connect(fs, &SingleFileSender::begin, this, &FilesSender::process_begin);
		connect(fs, &SingleFileSender::complete, this, &FilesSender::process_complete);
		fs->floderName = basepath.toLocal8Bit();
		fs->fileName = filename[i].toLocal8Bit();
		sthreadpool.start(fs);
	}
}

void SingleFileSender::run()
{
	emit begin(seqID);
	const int RecDataSize = 255;
	WORD SockVersion = MAKEWORD(2, 2);
	WSADATA WsaData;
	int CheckWSA = WSAStartup(SockVersion, &WsaData);
	if (CheckWSA != 0)return;
	SOCKET ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET)return;
	sockaddr_in ClientAddr;
	ClientAddr.sin_family = AF_INET;
	ClientAddr.sin_port = htons(8888);
	char IPdotdec[] = "139.159.159.236";
	inet_pton(AF_INET, IPdotdec, &ClientAddr.sin_addr.S_un);
	if (::connect(ClientSocket, (LPSOCKADDR)&ClientAddr, sizeof(ClientAddr)) == SOCKET_ERROR)
	{
		closesocket(ClientSocket);
		WSACleanup();
		return;
	}
	ifstream fp;
	fp.open(floderName + fileName, ios::binary);
	fp.seekg(0, ios::end);
	unsigned int fileSize = fp.tellg();


	int CheckSend;
	unsigned char buffer[1024];

	/*��֪��������ʼ�ϴ��ļ�*/
	unsigned int x = 3, beginPosition = 0;
	memset(buffer, 0, 1024);
	memcpy_s(&buffer[0], 4, &x, 4);
	memcpy_s(&buffer[4], 4, &fileSize, 4);
	memcpy_s(&buffer[8], 4, &beginPosition, 4);
	memcpy_s(&buffer[12], 1012, fileName.c_str(), fileName.length());
	const char* SendLength = (char*)buffer;
	CheckSend = send(ClientSocket, SendLength, 1024, 0);

	/*�ƶ��ļ�ָ��*/
	int l = recv(ClientSocket, (char*)&beginPosition, 4, 0);
	fp.seekg(beginPosition, ios::beg);

	for (unsigned int i = beginPosition; i < fileSize; i += CheckSend)
	{
		fp.read((char*)buffer, 1024);
		const unsigned char* SendData = buffer;
		CheckSend = send(ClientSocket, (char*)SendData, fp.gcount(), 0);

		if (CheckSend == SOCKET_ERROR || CheckSend == 0)
		{
			closesocket(ClientSocket);
			WSACleanup();
			emit complete(seqID, false, "����ʧ��");
			return;
		}
	}
	fp.seekg(0, ios::beg);
	CheckSend = recv(ClientSocket, (char*)buffer, 33, 0);
	if (CheckSend == SOCKET_ERROR || CheckSend == 0)
	{
		emit complete(seqID, false, "����ʧ��");
	}
	else
	{
		MD5 md5;
		md5.update(ifstream(floderName + fileName));
		string res = md5.toString();
		if (strcmp(res.c_str(), (char*)buffer) != 0)
		{
			char msg[] = "md5 check error";
			send(ClientSocket, msg, 16, 0);
			emit complete(seqID, false, "��֤ʧ��");
			return;
		}
		else
		{
			char msg[] = "finish";
			send(ClientSocket, msg, 16, 0);
		}
	}
	closesocket(ClientSocket);
	WSACleanup();
	emit complete(seqID, true, "");
	return;
}

void FilesSender::StopSending()
{
	
}

void FilesSender::process_begin(unsigned short id)
{
	emit rpt_process(id, QString::fromLocal8Bit("��ʼ����"));
}
void FilesSender::process_process(unsigned short id, int value)
{
	emit rpt_process(id, QString::fromLocal8Bit("������"));
}
void FilesSender::process_complete(unsigned short id, bool success, QString msg)
{
	emit rpt_process(id, QString::fromLocal8Bit(success ? "�������" : "����ʧ��"));
}


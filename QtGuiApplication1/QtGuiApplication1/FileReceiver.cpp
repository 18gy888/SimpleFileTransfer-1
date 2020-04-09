#include "FileReceiver.h"


void SingleFileReceiver::run()
{
	unsigned char RevData[1024];
	ofstream fileWriter;
	
	int rev = recv(socket, (char*)RevData, 1024, 0);
	if (rev > 0)
	{
		unsigned int fileLength;
		string fileName = (char*)&RevData[12];
		string fullPath = saveFlod + fileName;
		string tempfile = fullPath;
		tempfile.replace(tempfile.begin() + tempfile.find_last_of('.'), tempfile.end(), ".tmp");
		memcpy_s(&fileLength, 4, &RevData[4], 4);

		unsigned int requestPosition;
		fileWriter.open(fullPath, ios::_Nocreate | ios::binary);

		/*���ж��ļ��Ƿ���Ҫ�ϵ�����*/
		if (fileWriter.is_open()) // ����ļ��Ѿ�����
		{
			ifstream readTmpFile;
			readTmpFile.open(tempfile);
			if (readTmpFile.is_open())readTmpFile >> requestPosition;
			else requestPosition = 0;
			readTmpFile.close();
		}
		else // ����ļ�û������
		{
			fileWriter.open(fullPath, ios::app | ios::binary);
			fileWriter.seekp(fileLength, ios::beg);
			requestPosition = 0;
		}

		/*����ͻ��˴�ָ��λ�ÿ�ʼ�����ļ�*/
		send(socket, (char*)&requestPosition, 4, 0);

		/*��ʼ�����ļ�*/
		fileWriter.seekp(requestPosition, ios::beg);
		for (unsigned int i = requestPosition; i < fileLength;)
		{
			rev = recv(socket, (char*)RevData, 1024, 0);

			/* ��������ж� */
			if (isInterruptionRequested() || rev == SOCKET_ERROR|| rev == 0)
			{
				/*��¼��ǰ���ؽ���*/
				ofstream writetemp;
				writetemp.open(tempfile, ios::trunc);
				writetemp << i;
				writetemp.close();
				fileWriter.close();
				closesocket(socket);
				return;
			}

			i += rev;
			fileWriter.write((char*)RevData, rev);
		}
		fileWriter.close();
		char msg[] = "finish";
		send(socket, msg, 7, 0);
		closesocket(socket);
	}
}
void Listener::run()
{
	const int DataSize = 255;
	WORD SockVertion = MAKEWORD(2, 2);
	WSADATA WsaData;
	int CheckWSA = WSAStartup(SockVertion, &WsaData);
	if (CheckWSA != 0) return;
	SOCKET SeverListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SeverListen == INVALID_SOCKET)return;
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (::bind(SeverListen, (SOCKADDR*)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)return;
	if (listen(SeverListen, 5) == SOCKET_ERROR)return;

	SOCKET ClientSocket;
	sockaddr_in RemoteAddr;
	int RemoteAddrSize = sizeof(RemoteAddr);
	char RevData[DataSize + 1];
	FILE* fp = NULL;
	errno_t err = 0;
	/*err = fopen_s(&fp, "D:\\result.txt", "w");
	if (err != 0) return;*/
	SingleFileReceiver fr;

	while (1)
	{
		ClientSocket = accept(SeverListen, (SOCKADDR*)&RemoteAddr, &RemoteAddrSize);
		if (ClientSocket != INVALID_SOCKET)
		{
			emit IncommingFile(ClientSocket);
			//break;
		}
	}
}
void FilesReceiver::BeginListening()
{
	Listener* listener = new Listener;
	qRegisterMetaType<SOCKET>("SOCKET");
	connect(listener, &Listener::IncommingFile, this, &FilesReceiver::ReceiveSingleFile);
	listener->start();
//
//	const int DataSize = 255;
//	WORD SockVertion = MAKEWORD(2, 2);
//	WSADATA WsaData;
//	int CheckWSA = WSAStartup(SockVertion, &WsaData);
//	if (CheckWSA != 0) return;
//	SOCKET SeverListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (SeverListen == INVALID_SOCKET)return;
//	sockaddr_in sin;
//	sin.sin_family = AF_INET;
//	sin.sin_port = htons(8888);
//	sin.sin_addr.S_un.S_addr = INADDR_ANY;
//	if (::bind(SeverListen, (SOCKADDR*)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)return;
//	if (listen(SeverListen, 5) == SOCKET_ERROR)return;
//
//	SOCKET ClientSocket;
//	sockaddr_in RemoteAddr;
//	int RemoteAddrSize = sizeof(RemoteAddr);
//	char RevData[DataSize + 1];
//	FILE* fp = NULL;
//	errno_t err = 0;
//	/*err = fopen_s(&fp, "D:\\result.txt", "w");
//	if (err != 0) return;*/
//	SingleFileReceiver fr;
//	
//	connect(&fr, &SingleFileReceiver::finished, this, &FilesReceiver::SingleFileFinished);
//	while (ctnListen) {
//		ClientSocket = accept(SeverListen, (SOCKADDR*)&RemoteAddr, &RemoteAddrSize);
//		if (ClientSocket == INVALID_SOCKET)continue;
//
//		fr.socket = ClientSocket;
//		fr.start();
//
//		fr.wait();
//		/*fclose(fp);*/
//
//		closesocket(ClientSocket);
//	}
//	closesocket(SeverListen);
//	WSACleanup();
//
//	return;
}

void FilesReceiver::SingleFileFinished()
{
	emit SingleFileGot();
}

void FilesReceiver::ReceiveSingleFile(SOCKET socket)
{
	SingleFileReceiver* fr = new SingleFileReceiver;
	fr->saveFlod = R"(D:\FileTransfer\)";
	connect(fr, &SingleFileReceiver::finished, this, &FilesReceiver::SingleFileFinished);
	fr->socket = socket;
	fr->start();
}

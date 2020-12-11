#pragma once
#include "MChar.h"
// ͨ��
typedef struct MSGCOMMON 
{
	size_t len;
	size_t checknum;
}*LPMSGCOMMON;

typedef struct FD_INFO 
{
	MChar pBuffer;
}*LPFD_INFO;

class SocketCompose
{
public:
	SocketCompose();
	~SocketCompose();
private:
	//����ְ�
	int long_hBuffer(FD_INFO * arg, const char * pBuffer, size_t Size);
public:
	//����ʱ����
	virtual int split_hBuffer(FD_INFO * arg,const char *pBuffer, size_t Size);
	virtual int complete_hBuffer(FD_INFO * arg,const char * pBuffer, size_t Size);
};


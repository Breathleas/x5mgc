#pragma once
#include "../Utils.h"
#include "RoomProxyInfo.h"
#include "UserIdentity.h"
class CEventQueryVideoAccountInfoRes : public ProtoBufSerializable
{
public:
	CEventQueryVideoAccountInfoRes();
	~CEventQueryVideoAccountInfoRes();
	void Reset();
	virtual void * operator[](string name);
public:
	int time_stamp = 1;// ����ʱ��
	bool succ = false;//�Ƿ�ɹ�������false����������Ϣ��Ч
	std::vector<RoomProxyInfo *> room_proxy_infos;  //��ѡ����room_proxy��Ϣ
	std::vector<UserIdentity *> account_infos; //��Ƶ��ɫ��Ϣ
	int err_code = 0;//������
	UserIdentity last_login_acc;//�ϴε�¼�Ľ�ɫ
};


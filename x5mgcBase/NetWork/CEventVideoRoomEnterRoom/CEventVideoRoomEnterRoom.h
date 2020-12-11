#pragma once
#include "../Utils.h"

class CEventVideoRoomEnterRoom : public ProtoBufSerializable
{
public:
	CEventVideoRoomEnterRoom();
	~CEventVideoRoomEnterRoom();
	virtual void * operator[](string name);
public:
	int room_id = 0;
	string nick;
	int gender = 0;
	int level = 0;
	bool has_avatar = false;
	NetBuffer avatar;
	int source = 0;
	bool invisible = false;
	bool crowd_into = false;//9
	int room_temp = 0;
	int subject = -1; // ҳǩ����� //11
	int tag = 0;// �Զ���ҳǩid
	int offset = 0;// ���ٽ���ƫ����
	int module_type = 0;// �����Ƽ�����ģ����� 0:��ģ��	1:�Ƽ�ģ��1	2:�Ƽ�ģ��2	3:�ݳ���ģ��
	int page_capacity = 0;// ÿҳ������
	int room_list_pos = 0;//15 // ���������б��ϵ�λ��
	vector<int> room_index; //17
	string token;//18
};


#pragma once
#define CLSID_CEventRoomProxyWrapEvent 40113 //���ܰl��

#define CLSID_CEventGetVideoHistoryInfo 41501 //�@ȡ�vʷ�б�
#define CLSID_CEventGetVideoHistoryInfoRes 41502 //������ʷ�б�


#define CLSID_CEventGetActivityCenterInfos  54510 //�@ȡ�΄��б�
#define CLSID_CEventGetActivityCenterInfosRes 54511 //���������ػ��S�б�

#define CLSID_CEventGetVideoMainInfos 62199 //��ȡ��ҳ
#define CLSID_CEventGetVideoMainInfosRes 62200 //��ȡ��ҳ����



#define CLSID_CEventGetSigninRewardNotify 41225 //
#define CLSID_CEventGetSigninRewardNotifyRes 41226 //��ȡ��¼ǩ��



#define CLSID_CEventVideoRoomEnterRoom 39782//���뷿��
#define CLSID_CEventVideoRoomEnterRoomRes 39783//���뷿��ص�

#define CLSID_CEventVideoRoomLeaveRoom 39784//�뿪����

#define CLSID_CEventVideoRoomShareConfig 39805 //ҕ�l����

#define CLSID_CEventQueryVideoAccountInfo 60001 //�@ȡ�������б�
#define CLSID_CEventQueryVideoAccountInfoRes 60002 //����������


#define CLSID_CEventVideoInitConnectionRequest 40201 //���朽�

#define CLSID_CEventVideoInitConnectionResponse 40202 //���朽ӷ���������

//�������ݷ���
#define CLSID_CEventVideoSendGiftResult 39730 //���Ƶ������Ʒ���


#define CLSID_VideoSurpriseBoxEventIDStart 38600//��ϲ���¼�ID��ʼ


#define CLSID_CEventVideoToClientChatMessage 39717//��Ƶ���ͻ���������Ϣ


#define CLSID_CEventVideoRoomLuckyDrawActivityInfo 41355//��ҽ���������һ����ѳ齱ʱ��

#define CLSID_CEventIgnoreFreeGift 41353//�������������Ϣ

#define CLSID_CEventIgnoreFreeGiftRes 41354//�������������Ϣ����



#define CLSID_CEventRefreshVideoCharInfoToClient 39921//������Ƶ�˺���Ϣ 39921
//public static const CLSID_CEventGetVideoPlayerInfo : int = 39923;
//public static const CLSID_CEventGetVideoPlayerInfoRes : int = 39924;
#define CLSID_CEventGetVideoPlayerInfo 39923//��ȡ��Ϣ
#define CLSID_CEventGetVideoPlayerInfoRes 39924//��ȡ�ص�


#define CLSID_CEventVideoPlayerHeartBeatNotify 39925 //������;




#define CLSID_CEventGetPlayerBasicCardInfo 38782 //f8386b ��ȡ�˺���Ϣ

#define CLSID_CEventGetPlayerBasicCardInfoRes 38783 //���ػص�

struct update_user
{
	uint32_t user;
	int zone_id;
	char mac_id[34];
	char msky[34];
	char open_id[34];
	char androidMd5[34];
	char mobile_version[10];
	void * theadPtr;
	void * thisPtr;
	void * x5MgcPrt;
	update_user()
	{
		memset(this, 0, sizeof(update_user));
	}
};

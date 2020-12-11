#pragma once
#include "../Utils.h"
#include "AnchorImpressionDataServer.h"
#include "SplitScreenInfo.h"
#include "VideoResolution.h"
#include <map>
class VideoRoomLiveStatusDetail :public ProtoBufSerializable
{
public:
	VideoRoomLiveStatusDetail();
	~VideoRoomLiveStatusDetail();
	void Reset();
	virtual void * operator[](string name);
public:
	string vid;
	int64_t anchor_pstid = 0;
	int start_time = 0;
	int sex = 0;
	std::string name;
	std::string description;
	int popularity = 0;
	int startlight = 0;
	std::string place;
	int followed = 0;//��˿����
	std::string deputy_anchor_name;
	std::string deputy_anchor_zone_name;
	int64_t deputy_anchor_id = 0;
	int talent_show_rank  = 0;
	bool star_anchor  = false;
	int pk_winner_order = 0;
	int vid2 = 0;
	int starlight_needed =0;
	AnchorImpressionDataServer  impression;
	int twoweek_starlight = 0;
	int anchor_type = 0;
	int level = 0;
	int server_id = 0;
	std::map<int*, std::string*> extra_vid;
	std::string m_anchor_url;
	SplitScreenInfo split_screen_info;
	bool is_anchor_pk_anchor = false;
	int anchor_level = 0;//�����ȼ�
	int anchor_exp = 0;//��������
	int anchor_levelup_exp = 0;//�����������辭��
	bool is_bottleneck = false;//�Ƿ���ƿ����
	int bottleneck_count = 0;//��������
	int bottleneck_need_count = 0;//ͻ����Ҫ����������
	int bottleneck_gift_id = 0;//ͻ��������Ҫ������id
	int buff_percent = 0;//���������ṩ������
	int starlight_rest_exp_today = 0;//ͨ������ҫֵ�������ӵ���������
	int dream_gift_rest_exp_today = 0;//���λñ����ﻹ�����ӵ���������
	int anchor_badge = 0;
	/**
	* 41 ���ճ齱�������ӵ���������ֵ
	*/
	int lucky_draw_rest_exp_tody = 0;
	std::map<int *, VideoResolution *> vid_resolutions;
	int fps = 0;
	/**
	 *  ����������
	 *  CDT_INVALID = -1,
	 *  CDT_PC = 0,
	 *  CDT_Android,
	 *	CDT_WEB,
	 *	CDT_SDK,
	 *	CDT_QGAME,
	 *	CDT_IFRAME,
	 *	CDT_X52,
	 *	CDT_IOS
	 */
	int anchor_device_type = -1;
	bool is_vertical_live = false;
	int f4412T = 0;
	int f4413U = 0;
	bool f4414V = 0;

	bool f4440z = 0;
	int f4393A = 0;
};


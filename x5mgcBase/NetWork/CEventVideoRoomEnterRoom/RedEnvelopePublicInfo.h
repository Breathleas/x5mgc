#pragma once
#include "../Utils.h"
#include "RedEnvelopeGrabberInfo.h"

class RedEnvelopePublicInfo :public ProtoBufSerializable
{
public:
	RedEnvelopePublicInfo();
	~RedEnvelopePublicInfo();
	virtual void * operator[](string name);
public:
	int64_t publisher = 0;
	std::string nick;
	std::string zone ;
	int publish_time = 0;
	int total_money = 0;
	int divide_count = 0;
	int64_t red_id = 0;
	int room_audience_count = 0; //����������
	int delay_audience_count = 0;//�ӳٲ�������
	int red_envelope_duration = 0;//��ʶ��������ʱ�䣬��λΪ�롣
	int small_red_envelope_duration = 0;//��ʶС�������ʱ�䣬��λΪ�롣
private:

};


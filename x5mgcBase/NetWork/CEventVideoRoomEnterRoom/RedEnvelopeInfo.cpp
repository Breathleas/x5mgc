#include "RedEnvelopeInfo.h"

RedEnvelopeInfo::RedEnvelopeInfo():ProtoBufSerializable(this)
{
	registerField("publisher", "", Descriptor::Int64, 1);// ���������
	registerField("nick", "", Descriptor::TypeString, 2);// �ǳ�
	registerField("zone", "", Descriptor::TypeString, 3);// ������
	registerField("publish_time", "", Descriptor::Int32, 4);// �����ʱ��
	registerField("total_money", "", Descriptor::Int32, 5);// ����ܶ��
	registerField("remain_money", "", Descriptor::Int32, 6);// ���ʣ��Ǯ��
	registerField("divide_count", "", Descriptor::Int32, 7);// ����ַ�����
	registerFieldForList("grabbers", typeid(RedEnvelopeGrabberInfo).name(), Descriptor::Compound, 8);// �������¼
	registerField("red_id", "", Descriptor::Int64, 9);// ���id
}

RedEnvelopeInfo::~RedEnvelopeInfo()
{
	for (size_t i = 0; i < grabbers.size(); i++)
	{
		delete grabbers[i];
	}
	grabbers.clear();
}

void * RedEnvelopeInfo::operator[](string name)
{
	if (name == "publisher"){
		return &this->publisher;
	}
	else if (name == "nick") {
		return &this->nick;
	}
	else if (name == "zone") {
		return &this->zone;
	}
	else if (name == "publish_time") {
		return &this->publish_time;
	}
	else if (name == "total_money") {
		return &this->total_money;
	}
	else if (name == "remain_money") {
		return &this->remain_money;
	}
	else if (name == "divide_count") {
		return &this->divide_count;
	}
	else if (name == "grabbers") {
		return &this->grabbers;
	}
	else if (name == "red_id") {
		return &this->red_id;
	}
	return nullptr;
}

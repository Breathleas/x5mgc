#include "RedEnvelopeGrabberInfo.h"

RedEnvelopeGrabberInfo::RedEnvelopeGrabberInfo():ProtoBufSerializable(this)
{
	registerField("grabber", "", Descriptor::Int64, 1);// ���������id
	registerField("nick", "", Descriptor::TypeString, 2);// �ǳ�
	registerField("zone", "", Descriptor::TypeString, 3);// ������
	registerField("grab_count", "", Descriptor::Int32, 4);// ����������
}

RedEnvelopeGrabberInfo::~RedEnvelopeGrabberInfo()
{

}

void * RedEnvelopeGrabberInfo::operator[](string name)
{
	if (name == "grabber"){
		return &this->grabber;
	}
	else if (name == "nick") {
		return &this->nick;
	}
	else if (name == "zone") {
		return &this->zone;
	}
	else if (name == "grab_count") {
		return &this->grab_count;
	}
	return nullptr;
}

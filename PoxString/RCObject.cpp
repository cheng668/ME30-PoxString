#include "RCObject.h"
/*���û�������������ʼֵ*/
RCObject::RCObject():refCount(0)
{
}

RCObject::RCObject(const RCObject& rhs) : refCount(0)
{
}
/*�˼̳�����󲻻ᱻ��ֵ��ֻ�����û���PoxString����ֵ*/
RCObject& RCObject::operator=(const RCObject& rhs)
{
	return *this;
}
/*����������*/
void RCObject::addRef()
{
	++refCount;
}
/*���������٣����Ϊ0����ɾ������*/
void RCObject::removeRef()
{
	if (--refCount == 0)
	{
		delete this;
	}
}
/*�����Ƿ񱻹���*/
bool RCObject::isShared() const
{
	return refCount > 1;
}

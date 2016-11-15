#include "RCObject.h"
/*由用户决定引用数初始值*/
RCObject::RCObject():refCount(0)
{
}

RCObject::RCObject(const RCObject& rhs) : refCount(0)
{
}
/*此继承族对象不会被赋值，只会是用户类PoxString被赋值*/
RCObject& RCObject::operator=(const RCObject& rhs)
{
	return *this;
}
/*引用数增加*/
void RCObject::addRef()
{
	++refCount;
}
/*引用数减少，如果为0，则删除对象*/
void RCObject::removeRef()
{
	if (--refCount == 0)
	{
		delete this;
	}
}
/*对象是否被共享*/
bool RCObject::isShared() const
{
	return refCount > 1;
}

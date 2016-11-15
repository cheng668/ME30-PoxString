#pragma once
class RCObject
{
public:
	/*构造*/
	RCObject();
	RCObject(const RCObject& rhs);
	/*此类为接口类*/
	virtual ~RCObject() = 0;
	/*引用数相关工具函数*/
	void addRef();
	void removeRef();
	bool isShared() const;
protected:
	/*此继承族对象不会被赋值，所以拷贝赋值函数不对外开放*/
	RCObject& operator=(const RCObject& rhs);
private:
	/*引用数*/
	int refCount;
};


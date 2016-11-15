#pragma once
class RCObject
{
public:
	/*����*/
	RCObject();
	RCObject(const RCObject& rhs);
	/*����Ϊ�ӿ���*/
	virtual ~RCObject() = 0;
protected:
	/*�˼̳�����󲻻ᱻ��ֵ�����Կ�����ֵ���������⿪��*/
	RCObject& operator=(const RCObject& rhs);
	/*��������ع��ߺ���*/
	void addRef();
	void removeRef();
	bool isShared() const;
private:
	/*������*/
	int refCount;
};


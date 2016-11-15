#pragma once
class RCObject
{
public:
	/*����*/
	RCObject();
	RCObject(const RCObject& rhs);
	/*����Ϊ�ӿ���*/
	virtual ~RCObject() = 0;
	/*��������ع��ߺ���*/
	void addRef();
	void removeRef();
	bool isShared() const;
protected:
	/*�˼̳�����󲻻ᱻ��ֵ�����Կ�����ֵ���������⿪��*/
	RCObject& operator=(const RCObject& rhs);
private:
	/*������*/
	int refCount;
};


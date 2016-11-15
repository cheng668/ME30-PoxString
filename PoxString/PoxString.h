#pragma once
#include "PoxChar.h"
#include "RCObject.h"
#include "RCPtr.h"
/*���ü���ʵ����*/
struct StringValue :public RCObject
{
	friend class PoxChar;
	~StringValue();
	StringValue(const StringValue& rhs);
	StringValue(const char* initvalue);
private:
	void init(const char* initvalue);
	char* m_pValue;
};
/*�û���*/
class PoxString
{
public:
	friend class PoxChar;
	/*�ӳپ�������ֵ������ֵ*/
	PoxChar operator[](const int index);
	const PoxChar operator[](const int index) const;
private:
	RCPtr<StringValue> value;
};


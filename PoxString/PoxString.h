#pragma once
#include "PoxChar.h"
#include "RCObject.h"
#include "RCPtr.h"
/*引用计数实现类*/
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
/*用户类*/
class PoxString
{
public:
	friend class PoxChar;
	/*延迟决定是左值还是右值*/
	PoxChar operator[](const int index);
	const PoxChar operator[](const int index) const;
private:
	RCPtr<StringValue> value;
};


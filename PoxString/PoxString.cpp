#include "PoxString.h"
#include "string.h"
/*拷贝构造*/
StringValue::StringValue(const StringValue& rhs)
{
	init(rhs.m_pValue);
}
/*构造*/
StringValue::StringValue(const char* initvalue)
{
	init(initvalue);
}
/*深拷贝*/
void StringValue::init(const char* initvalue)
{
	m_pValue = new char[strlen(initvalue) + 1];
	strcpy_s(m_pValue, strlen(initvalue) + 1, initvalue);
}
/*删除指针*/
StringValue::~StringValue()
{
	delete[] m_pValue;
}
/*延迟觉得是左值还是右值*/
PoxChar PoxString::operator[](const int index)
{
	return PoxChar(*this, index);
}
const PoxChar PoxString::operator[](const int index) const
{
	return PoxChar(const_cast<PoxString&> (*this), index);
}
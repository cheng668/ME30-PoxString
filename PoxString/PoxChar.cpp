#include "PoxChar.h"
#include "PoxString.h"
#include "RCPtr.h"
/*构造函数*/
PoxChar::PoxChar(PoxString& str,const int idx):m_theString(str),m_iIdx(idx)
{
}
/*当需要使用左值时创建新对象，并赋值*/
void PoxChar::assignment(const char c)
{
	if (m_theString.value->isShared())
	{
		/*调用RCPtr(const T* rhs = 0)隐式转换为RCPtr<StringValue>*/
		m_theString.value = new StringValue(m_theString.value->m_pValue);
	}
	m_theString.value->m_pValue[m_iIdx] = c;
}
/*左值运用*/
PoxChar& PoxChar::operator=(const PoxChar& rhs)
{
	assignment(rhs.m_theString.value->m_pValue[m_iIdx]);
	return *this;
}
/*左值运用*/
PoxChar& PoxChar::operator=(const char c)
{
	assignment(c);
	return *this;
}
/*当需要使用右值时隐式转换为char类型*/
PoxChar::operator char() const
{
	return m_theString.value->m_pValue[m_iIdx];
}

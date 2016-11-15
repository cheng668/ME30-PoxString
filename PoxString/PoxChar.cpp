#include "PoxChar.h"
#include "PoxString.h"
#include "RCPtr.h"
/*���캯��*/
PoxChar::PoxChar(PoxString& str,const int idx):m_theString(str),m_iIdx(idx)
{
}
/*����Ҫʹ����ֵʱ�����¶��󣬲���ֵ*/
void PoxChar::assignment(const char c)
{
	if (m_theString.value->isShared())
	{
		/*����RCPtr(const T* rhs = 0)��ʽת��ΪRCPtr<StringValue>*/
		m_theString.value = new StringValue(m_theString.value->m_pValue);
	}
	m_theString.value->m_pValue[m_iIdx] = c;
}
/*��ֵ����*/
PoxChar& PoxChar::operator=(const PoxChar& rhs)
{
	assignment(rhs.m_theString.value->m_pValue[m_iIdx]);
	return *this;
}
/*��ֵ����*/
PoxChar& PoxChar::operator=(const char c)
{
	assignment(c);
	return *this;
}
/*����Ҫʹ����ֵʱ��ʽת��Ϊchar����*/
PoxChar::operator char() const
{
	return m_theString.value->m_pValue[m_iIdx];
}

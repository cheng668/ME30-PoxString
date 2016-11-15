#include "PoxString.h"
#include "string.h"
/*��������*/
StringValue::StringValue(const StringValue& rhs)
{
	init(rhs.m_pValue);
}
/*����*/
StringValue::StringValue(const char* initvalue)
{
	init(initvalue);
}
/*���*/
void StringValue::init(const char* initvalue)
{
	m_pValue = new char[strlen(initvalue) + 1];
	strcpy_s(m_pValue, strlen(initvalue) + 1, initvalue);
}
/*ɾ��ָ��*/
StringValue::~StringValue()
{
	delete[] m_pValue;
}
/*�ӳپ�������ֵ������ֵ*/
PoxChar PoxString::operator[](const int index)
{
	return PoxChar(*this, index);
}
const PoxChar PoxString::operator[](const int index) const
{
	return PoxChar(const_cast<PoxString&> (*this), index);
}
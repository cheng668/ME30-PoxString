#pragma once
class PoxString;
class PoxChar
{
public:
	/*����*/
	PoxChar(PoxString& str,const int idx);
	/*��ֵ����*/
	PoxChar& operator=(const PoxChar& rhs);
	PoxChar& operator=(const char c);
	/*��ֵ����*/
	operator char() const;
private:
	/*���ڼ�¼�ַ�����*/
	int m_iIdx;
	/*��PoxString���������*/
	PoxString& m_theString;
	void assignment(const char c);
};


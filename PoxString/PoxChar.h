#pragma once
class PoxString;
class PoxChar
{
public:
	/*构造*/
	PoxChar(PoxString& str,const int idx);
	/*左值运用*/
	PoxChar& operator=(const PoxChar& rhs);
	PoxChar& operator=(const char c);
	/*右值运用*/
	operator char() const;
private:
	/*用于记录字符索引*/
	int m_iIdx;
	/*对PoxString对象的引用*/
	PoxString& m_theString;
	void assignment(const char c);
};


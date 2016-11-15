#pragma once
/*����ֵ������*/
template<typename T>
class RCPtr {
public:
	RCPtr(const RCPtr& rhs);
	RCPtr(const T* rhs = 0);
	RCPtr& operator=(const RCPtr& rhs);
	T& operator*() const;
	T* operator->() const;
private:
	T* pointee;
	void init();
};
/*������������ֵ*/
template<typename T>
void
RCPtr<T>::init()
{
	if (pointee == 0)
	{
		return;
	}
	pointee->addRef();
}
/*��������*/
template<typename T>
RCPtr<T>::RCPtr(const RCPtr& rhs):pointee(rhs.pointee)
{
	init();
}
/*����*/
template<typename T>
RCPtr<T>::RCPtr(const T* rhs):pointee(rhs)
{
	init();
}
/*������ֵ*/
template<typename T>
RCPtr<T>&
RCPtr<T>::operator=(const RCPtr& rhs)
{
	if (rhs.pointee != pointee)
	{
		if (pointee != 0)
		{
			pointee->removeRef();
		}
		pointee = rhs.pointee;
		pointee->addRef();
	}

	return *this;
}
/*�������ü���ʵ�������ָ��*/
template<typename T>
T*
RCPtr<T>::operator->() const
{
	return pointee;
}
/*�������ü���ʵ�����������*/
template<typename T>
T&
RCPtr<T>::operator *()const
{
	return *pointee;
}
#pragma once
/*引用值管理类*/
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
/*拷贝增加引用值*/
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
/*拷贝构造*/
template<typename T>
RCPtr<T>::RCPtr(const RCPtr& rhs):pointee(rhs.pointee)
{
	init();
}
/*构造*/
template<typename T>
RCPtr<T>::RCPtr(const T* rhs):pointee(rhs)
{
	init();
}
/*拷贝赋值*/
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
/*返回引用计数实现类对象指针*/
template<typename T>
T*
RCPtr<T>::operator->() const
{
	return pointee;
}
/*返回引用计数实现类对象引用*/
template<typename T>
T&
RCPtr<T>::operator *()const
{
	return *pointee;
}
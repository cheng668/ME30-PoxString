# ME30-PoxString
程序来自《More Effective C++》条款30，书中还指出此程序的限制：
1.类型转换出错
  PoxString s1 = "test";
  char* p = &s1[1]; //这类取地址符号&会报错，因为没有从PoxChar到char*的转换
  
  解决方法：重载&操作符：
  const char* PoxChar::operator&() const
  {
    return &(m_theString.value->m_pValue[m_iIdx]);
  }
  char* PoxChar::operator&()
  {
    if(m_theString.value->isShared())
      m_theString.value = new PoxString(m_theString.value->m_pValue);
      
    m_theString.value->markUnshareable();
    
    return &(m_theString.value->m_pValue[m_iIdx]);
  }

2.很多操作符需要重载
  PoxString[5] = 22; //没问题
  PoxString[5] += 5;  //错误，没有从int到PoxChar的转换
  PoxString[5]++;     //错误，PoxChar不能进行++操作
  
  解决方法：重载操作符
  
3.不能通过PoxChar调用真实对象的成员函数
  如果char对象中有一个转换类型的函数 int toInt();
  那么调用
  PoxString s = "test";
  s[1].toInt();  //错误，PoxChar不存在toInt()函数
  
  解决方法：重载真实对象的成员函数
  
4.不能为转换引用类型
  void swap(char& a, char& b);
  PoxString s = "+C+";
  swap(s[0],s[1]);   //错误，没有从PoxChar到char&的转换
  
5.不能进行某些类型的隐式转换
  class TVStation{
  public:
    TVStation(char channel);
    ...
  };
  
  void watchTV(const TVStation& station ,float hoursToWatch);
  
  watchTV('c',2.5);  //int隐式转换为TVStation
  PoxString s = "test";
  watchTV(s[1],2.5);  //错误，用户定制转换函数的次数只限一次
  watchTV()
  

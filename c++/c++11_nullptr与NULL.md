# 为什么建议你用nullptr而不是NULL？

## **前言**

在C语言中，我们常常用NULL作为指针变量的初始值，而在C++中，却不建议你这么做。

## **NULL是什么**

在C的头文件中，通常定义如下：

```c++
#define NULL ((void*)0)
```



但是在C++中，它是这样定义的：

```c++
#define NULL 0
```

或者你可以在stddef.h看到完整的这段：

```c++
#undef NULL
#if defined(__cplusplus)
#define NULL 0
#else
#define NULL ((void *)0)
#endif
```

也就是说，在C++中，NULL不过也是0罢了，把它当成空指针只是一个无可奈何的选择罢了。

那么为什么在C++和C中不一样呢？因为C++中不能将void *类型的指针**隐式转换**成其他指针类型，从下面的例子可以看出来：

```javascript
//null.cpp
#include<iostream>
int main(void)
{
    char p[] = "12345";
    int *a = (void*)p;
    return 0;
}
```

编译：

```javascript
$ g+ -o null null.cpp
null.cpp: In function 'int main()':
null.cpp:5:17: error: invalid conversion from 'void*' to 'int*' [-fpermissive]
  int *a =(void*)p;
```

所以不能将NULL定义为(void*)0。

## **nullptr**

nullptr并非整型类别，甚至也不是指针类型，但是能转换成任意指针类型。nullptr的实际类型是std:nullptr_t。

> 来源：公众号【编程珠玑】，专注但不限于分享计算机编程基础，Linux，C语言，C++，数据结构与算法，工具，资源等编程相关[原创]技术文章。博客：https://www.yanbinghu.com/2019/08/25/36794.html

## **为什么该使用nullptr**

回到最开始的问题，为什么作为指针的语义，我们应该使用nullptr，而不是NULL。 请看下面的代码：

```javascript
//来源：公众号【编程珠玑】，https://www.yanbinghu.com
//test.cpp
#include<iostream>
using namespace std;
void test(void *p)
{
    cout<<"p is pointer "<<p<<endl;
}
void test(int num)
{
    cout<<"num is int "<<num<<endl;
}
int main(void)
{

    test(NULL);
    return 0;
}
```

编译：

```javascript
$ g++ -o test test.cpp
main.cpp: In function ‘int main()’:
main.cpp:16:14: error: call of overloaded ‘test(NULL)’ is ambiguous
     test(NULL);
```

很不幸，编译报错了，提示我们有二义性，按照《[重载函数匹配规则](http://mp.weixin.qq.com/s?__biz=MzI2OTA3NTk3Ng==&mid=2649284296&idx=1&sn=7bbce919d0c7f2f6f62623d7054a8dbc&chksm=f2f9adafc58e24b9db5a46249d0a3364265065e075f0e6066ee0e8a064aefc8c23ab3710a826&scene=21#wechat_redirect)》，两个都可以匹配，因此最终报错。

但是如果我们使用nullptr却不会：

```javascript
test(nullptr);
```

除了这点之外，在C++模板中它还有更好的表现。 看下面的代码：

```javascript
//来源：公众号【编程珠玑】，https://www.yanbinghu.com
#include<iostream>
using namespace std;
template<typename Type1,typename ptrType>
void test(Type1 fun,ptrType ptr)
{
    /*do something*/
    fun(ptr);
    return;
}
void fun(int *val)
{
    cout<<"fun"<<endl;
}
int main(void)
{
    test(fun,NULL);
    return 0;
}
```

编译报错了：

```javascript
main.cpp:8:8: error: invalid conversion from ‘long int’ to ‘int*’ [-fpermissive]
     fun(ptr);
```

很显然NULL被推导为long int，而不是空指针，因而导致函数类型不匹配而报错。

但是如果我们用nullptr就不会有上面的问题。

## **总结**

如果你想表示空指针，那么使用nullptr，而不是NULL。

注：nullptr在C++ 11中才出现。




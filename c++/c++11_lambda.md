####  lambda

一个lambda表达式表示一个可调用的代码单元。我们可以将其理解为一个未命名的内联函数。与任何函数类似，一个lambda 具有一个返回类型、一个参数列表和一个函数体。但与函数不同，lambda可能定义在函数内部。一个lambda表达式具有如下形式

```c++
[捕获列表](参数列表)->return type {function}

其中，capture list (捕获列表)是一个lambda所在函数中定义的局部变量的列表(通常为空); return type、parameter list和function body与任何普通函数一样， 分别表示返回类型、参数列表和函数体。但是，与普通函数不同，lambda 必须使用尾置返回来指定返回类型。
    
//我们可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体
auto fun = []{return 5};
```



```c++
[](const string &a,const string &b)//不能有默认参数
{
	return a.size()<b.size();
}

stable_sort(words.begin(),words.end() ,
[](const string &a， const string &b)
{ return a.size() < b.size() ; }) ;

```



```c++
//捕获列表
[sz](const string &a)
{
	return a.size () >= SZ;
};

```

- **捕获**

当定义一个lambda时，编译器生成一个与lambda对应的新的(未命名的)类类型。我们将在介绍这种类是如何生成的。目前，可以这样理解，当向一个函数传递一-个 lambda 时，同时定义了一个新类型和该类型的一个对象: 传递的参数就是此编译器生成的类类型的未命名对象。类似的，当使用auto定义一个用lambda初始化的变量时，定义了一个从lambda生成的类型的对象。

默认情况下，从lambda生成的类都包含一个对应该lambda所捕获的变量的数据成员。类似任何普通类的数据成员，lambda的数据成员也在lambda对象创建时被初始化。

- 值捕获

```c++
void fcnl ()
{
    size_ t v1 = 42; //局部变量
    //将v1拷贝到名为f的可调用对象
    autof=[v1]{returnv1;};
    v1=0;
    autoj=f();//于为42;f保存了我们创建它时v1的拷贝
}
```

- 引用捕获

```c++
void fcn2 ()
{
    size_tv1=42;//局部变量
    //-对象f2包含v1的引用
    auto f2 = [&v1] { return v1; };
    v1=0;
    autoj=f2();//j为0;f2保存v1的引用，而非拷贝
}

```

引用捕获与返回引用有着相同的问题和限制。如果我们采用引用方式捕获一个变量，就必须确保被引用的对象lambda执行的时候是存在的。lambda捕获的都是局部变量，这些变量在函数结束后就不复存在了。如果lambda可能在函数结束后执行，捕获的引用指向的局部变量已经消失。

**建议:尽量保持lambda的变量捕获简单化**
一个lambda捕获从lambda被创建(即，定义lambda的代码执行时)到lambda自身执行(可能有多次执行)这段时间内保存的相关信息。确保lambda每次执行的时候这些信息都有预期的意义，是程序员的责任。捕获一个普通变量，如int、string或其他非指针类型，通常可以采用简单的值捕获方式。在此情况下，只需关注变量在捕获时是否有我们所需的值就可以了。如果我们捕获一个指针或迭代器，或采用引用捕获方式，就必须确保在lambda执行时，绑定到迭代器、指针或引用的对象仍然存在。而且，需要保证对象具有预期的值。在lambda从创建到它执行的这段时间内，可能有代码改变绑定的对象的值。也就是说，在指针(或引用)被捕获的时刻，绑定的对象的值是我们所期望的，但在lambda 执行时，该对象的值可能已经完全不同了。一般来说，我们应该尽量减少捕获的数据量，来避免潜在的捕获导致的问题。而且，如果可能的话，应该避免捕获指针或引用。



- 隐式捕获

为了指示编译器推断捕获列表，应在捕获列表中写一个&或=。&告诉编译器采用捕获引用方式，=则表示采用值捕获方式。也可以混合使用

- 可变lambda

默认情况下，对于一个值被拷贝的变量，lambda 不会改变其值。如果我们希望能改变一个被捕获的变量的值，就必须在参数列表首加上关键字mutable。因此，可变lambda能省略参数列表:

```c++
void fcn3 ()
{
    size_t v1 = 42; //局部变量
    // f可以改变它所捕获的变量的值
    auto f =[v1] () mutable { return ++vl; } ;
    v1=0;
    autoj=f();//j为43
}
```



- lambda 返回类型

```c++
transform(vi.begin(),vi.end(), vi.begin() ,
[](int i){return i<0?-i:i;});//可不写返回类型

```

```c++
//错误:不能推断lambda的返回类型
transform (vi.begin(), vi.end() ，vi.begin() ,
[](int i){if(i<0)return-i;else return i;});
//多个return 推断为void

//必须写为
transform (vi.begin(), vi.end() ，vi.begin() ,
[](int i)->int{if(i<0)return-i;else return i;});
```



- 标准库bind函数

bind的标准库函数，它定义在头文件functional中。可以将bind函数看作一个通用的函数适配器,它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。

```c++
using namespace std::placeholders;
// check6是一个可调用对象，接受-一个string类型的参数
//并用此string和值6来调用check_ size
auto check6 = bind(check_size,_1, 6) ;


string s = "hello";
bool bl = check6(s); 
// check6(s) 会调用check_ size(s,6)

```



```c++
for_each (words .begin(),words.end() ,
bind (print, ref(os),_1,' '));
//标准库 ref 引用这里的os
```


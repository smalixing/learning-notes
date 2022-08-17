# C++：友元



**文章目录**

- 1 全局函数做友元

- 2 类做友元

- 3 成员函数做友元

  

  生活中你的家有客厅(public)，有你的卧室(private)
  客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去

  但是呢，你也可以允许 **隔壁老王** 进去。

在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的 就是让一个函数或者类 访问另一个类中的私有成员

友元的关键字为 **friend**

友元的三种实现

- 全局函数做友元

- 类做友元

- 成员函数做友元

  

## 1. 全局函数做友元
  首先，我们要定义一个房屋类，公共成员变量为客厅，私有成员变量为卧室

```c++
class Building
{
 public:
	// Building的构造函数，给成员变量赋初值
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	
	string m_SittingRoom;	// 客厅

private:

	string m_BedRoom;		// 卧室
};
```

然后定义一个全局函数 laoWang()，用来访问Building类中的私有成员

```c++
void laoWang1(Building *building)
{
	cout << "隔壁老王 全局函数 正在访问：（地址传递） " << building->m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（地址传递） " << building->m_BedRoom << endl;
}
```
当然也可以用引用传递或者最简单的值传递

```c++
void laoWang2(Building &building)
{
	cout << "隔壁老王 全局函数 正在访问：（引用传递） " << building.m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（引用传递） " << building.m_BedRoom << endl;
}

void laoWang3(Building building)
{
	cout << "隔壁老王 全局函数 正在访问：（ 值传递 ） " << building.m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（ 值传递 ） " << building.m_BedRoom << endl;
}
```
最后定义一个测试函数test()，实现 laoWang() 这个全局函数做友元访问类的私有成员

```c++
void test()
{
	Building building;
	laoWang1(&building);
	laoWang2(building);
	laoWang3(building);
}
```

但是，现在还不能实现全局函数访问类的私有成员！

关键代码

```c++
friend void laoWang1(Building *building);
friend void laoWang2(Building &building);
friend void laoWang3(Building building);
```
在Building类中声明友元函数，告诉编译器 laoWang全局函数是 Building类 的好朋友，可以访问Building对象的私有成员

```c++
class Building
{
	// 告诉编译器 laoWang全局函数是 Building类  的好朋友，可以访问Building对象的私有成员
	friend void laoWang1(Building *building);
	friend void laoWang2(Building &building);
	friend void laoWang3(Building building);

public:

	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	
	string m_SittingRoom;	// 客厅

private:

	string m_BedRoom;		// 卧室
};
```
下面给出全局函数做友元访问类的私有成员的完整示例代码

```c++
#include <iostream>
#include <string>

using namespace std;

// 房屋类
class Building
{
	// 告诉编译器 laoWang全局函数是 Building类  的好朋友，可以访问Building对象的私有成员
	friend void laoWang1(Building *building);
	friend void laoWang2(Building &building);
	friend void laoWang3(Building building);

public:

	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	
	string m_SittingRoom;	// 客厅

private:

	string m_BedRoom;		// 卧室
};



//全局函数
void laoWang1(Building *building)
{
	cout << "隔壁老王 全局函数 正在访问：（地址传递） " << building->m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（地址传递） " << building->m_BedRoom << endl;
}

void laoWang2(Building &building)
{
	cout << "隔壁老王 全局函数 正在访问：（引用传递） " << building.m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（引用传递） " << building.m_BedRoom << endl;
}

void laoWang3(Building building)
{
	cout << "隔壁老王 全局函数 正在访问：（ 值传递 ） " << building.m_SittingRoom << endl;

	cout << "隔壁老王 全局函数 正在访问：（ 值传递 ） " << building.m_BedRoom << endl;
}

void test()
{
	Building building;
	laoWang1(&building);
	laoWang2(building);
	laoWang3(building);
}


int main()
{
	test();
}
```
输出结果
```
隔壁老王 全局函数 正在访问：（地址传递） 客厅
隔壁老王 全局函数 正在访问：（地址传递） 卧室
隔壁老王 全局函数 正在访问：（引用传递） 客厅
隔壁老王 全局函数 正在访问：（引用传递） 卧室
隔壁老王 全局函数 正在访问：（ 值传递 ） 客厅
隔壁老王 全局函数 正在访问：（ 值传递 ） 卧室
```
## 2. 类做友元
首先，声明一个要访问的私有变量所属的Building类，防止在下面的好LaoWang类中，编译器不认识Building（当然也可以采取先定义Building类，再定义隔壁老王LaoWang类，这样就不用声明Building类了）
```
class Building;//前置声明
```
然后定义一个隔壁老王LaoWang类，声明了一个Building类型的指针变量building。其中，成员函数采用另一种方式：类内声明，类外定义，可以简化类的内容（在全局函数做友元的示例中，采用在类内声明并定义成员函数的方式，两种方式均可）
```c++
class Building;//前置声明
class LaoWang
{
public:
	//LaoWang的构造函数
	LaoWang();

	void visit();	//参观函数  访问Building中的属性
	
	Building * building;


private:


};
```
接着给出Building类的定义
```c++
class Building
{
public:
	//Building的构造函数类内声明，在类外定义
	Building();
		
	string m_SittingRoom;	// 客厅

private:
	
	string m_BedRoom;		// 卧室

};
```
下面给出类外定义成员函数，需要注意的是，在类外定义，需要在成员函数加上所在类的作用域（类名::成员函数名()），以便于告诉编译器，该成员函数属于哪个类。

```c++
//Building类的构造函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";

	cout << m_SittingRoom << endl;
	cout << m_BedRoom << endl;

}

//LaoWang的构造函数
LaoWang::LaoWang()
{
	// 创建建筑物对象
	building = new Building;	//在堆区开辟一块内存，并赋给building指针

}

//LaoWang的成员函数visit()
void LaoWang::visit()
{
	cout << "隔壁老王类正在访问：" << building->m_SittingRoom << endl;

	cout << "隔壁老王类正在访问：" << building->m_BedRoom << endl;
}
```
最后定义一个测试函数，实现类做友元访问其他类的私有成员

```c++
void test()
{
	LaoWang lw	//定义一个LaoWang类的对象;
	lw.visit();
}
```
但是，现在还不能实现一个类访问另一个类的私有成员！

关键代码
```
friend class LaoWang;
```
在Building类中声明一个友元类，告诉编译器 LaoWang类是 Building类 的好朋友，可以访问Building对象的私有成员
```c++
class Building
{
	// 告诉编译器，LaoWang类是Building类的好朋友，可以访问Building类的私有成员
	friend class LaoWang;
public:
	
	Building();
		
	string m_SittingRoom;	// 客厅

private:
	
	string m_BedRoom;		// 卧室

};
```
下面给出类做友元实现一个类访问另一个类私有成员的完整示例代码

```c++
#include <iostream>
#include <string>

using namespace std;

// 类作友元

class Building;
class LaoWang
{
public:

	LaoWang();
	
	void visit();	//参观函数  访问Building中的属性
	
	Building * building;


private:


};

// 房屋类
class Building
{
	// 告诉编译器，LaoWang类是Building类的好朋友，可以访问Building类的私有成员
	friend class LaoWang;
public:
	
	Building();
		
	string m_SittingRoom;	// 客厅

private:
	
	string m_BedRoom;		// 卧室
};

// 类外定义成员函数

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

LaoWang::LaoWang()
{
	// 创建建筑物对象
	building = new Building;
}

void LaoWang::visit()
{
	cout << "隔壁老王LaoWang类正在访问：" << building->m_SittingRoom << endl;

	cout << "隔壁老王LaoWang类正在访问：" << building->m_BedRoom << endl;
}

void test()
{
	LaoWang lw;
	lw.visit();
}

int main()
{
	test();

	return 0;
}
```
输出结果

```
隔壁老王LaoWang类正在访问：客厅
隔壁老王LaoWang类正在访问：卧室
```

## 3. 成员函数做友元
类似于类作友元，我们首先声明一个Building类，防止在下面的好LaoWang类中，编译器不认识Building
```
class Building;
```
然后定义LaoWang类，同样采用成员函数在类内声明，类外定义的方式。其中定义两个访问函数

visit1()，可以 访问Building中的私有成员
       visit2()，不可以 访问Building中的私有成员

```c++
class LaoWang
{
public:

	LaoWang();
	void visit1();	//让visit1()函数   可以 访问Building中的私有成员
	void visit2();	//让visit2()函数 不可以 访问Building中的私有成员
	
	Building *building;

private:

};
```
下面给出Building类的定义

```c++
class Building
{
public:
	Building();

	string m_SittingRoom;	//客厅

private:

	string m_BedRoom;		//卧室
};
```
下面给出类外定义成员函数

```c++
//LaoWang类的构造函数
LaoWang::LaoWang()
{
	building = new Building;
}

//LaoWang类的成员函数visit1()
void LaoWang::visit1()
{
	cout << "隔壁老王LaoWang类中的visit1()函数正在访问：" << building->m_SittingRoom << endl;
	cout << "隔壁老王LaoWang类中的visit1()函数正在访问：" << building->m_BedRoom << endl;	
}

//LaoWang类的成员函数visit2()
void LaoWang::visit2()
{
	cout << "隔壁老王LaoWang类中的visit2()函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "隔壁老王LaoWang类中的visit2()函数正在访问：" << building->m_BedRoom << endl;	//错误！私有属性不可访问
}

//Building类的构造函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
```
最后用一个测试函数实现成员函数做友元实现对另一个类私有成员的访问

```c++
void test()
{
	LaoWang lw;
	
	lw.visit1();
	
	lw.visit2();
}
```
同样的，现在还没有声明友元，因此类中的成员函数还不能访问另一个类的私有成员

关键代码

```
friend void LaoWang::visit1();
```
在Building类中声明一个友元成员函数，告诉编译器 **visit1()**成员函数是 Building类 的好朋友，可以访问Building对象的私有成员

```c++
class Building
{
	// 告诉编译器，LaoWang类下的visit1()函数是Building类的好朋友，可以访问Building的私有成员
	friend void LaoWang::visit1();

public:
	Building();

	string m_SittingRoom;	//客厅

private:

	string m_BedRoom;		//卧室
};
```
下面给出成员函数做友元实现一个类的成员函数访问另一个类私有成员的完整示例代码

```c++
#include <iostream>
#include <string>

using namespace std;

class Building;

class LaoWang
{
public:

	LaoWang();
	void visit1();	//让visit1()函数   可以 访问Building中的私有成员
	void visit2();	//让visit2()函数 不可以 访问Building中的私有成员
	
	Building *building;

private:


};

class Building
{
	// 告诉编译器，LaoWang类下的visit1()函数是Building类的好朋友，可以访问Building的私有成员
	friend void LaoWang::visit1();

public:
	Building();

	string m_SittingRoom;	//客厅
private:

	string m_BedRoom;		//卧室
};


LaoWang::LaoWang()
{
	building = new Building;
}

void LaoWang::visit1()
{
	cout << "隔壁老王LaoWang类中的visit1()函数正在访问：" << building->m_SittingRoom << endl;
	cout << "隔壁老王LaoWang类中的visit1()函数正在访问：" << building->m_BedRoom << endl;
}

void LaoWang::visit2()
{
	cout << "隔壁老王LaoWang类中的visit2()函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "隔壁老王LaoWang类中的visit2()函数正在访问：" << building->m_BedRoom << endl;	//错误！私有属性不可访问
}

Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

void test()
{
	LaoWang lw;
	
	lw.visit1();
	
	lw.visit2();
}

int main()
{
	test();
	
	return 0;
}
```
输出结果
```
隔壁老王LaoWang类中的visit1()函数正在访问：客厅
隔壁老王LaoWang类中的visit1()函数正在访问：卧室
隔壁老王LaoWang类中的visit2()函数正在访问：客厅
```

————————————————
版权声明：本文为CSDN博主「孙 悟 空」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_46098577/article/details/116596183
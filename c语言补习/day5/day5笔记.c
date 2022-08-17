字符串:
	一串单个的字符的集合 "abcd"
	字符串末尾一定有'\0'
	用字符数组存储字符串
	char a[] = "abc"; sizeof a == 4;
	
	//char a[4] = "abcd"; //err
	
	char a[20];
	//a[0] = "你"; //err
	char b[] = "你";
	for(int i = 0; b[i]; i++)
		a[i] = b[i];

有效字符:
	字符串中第一个'\0'之前的字符叫做有效字符
	char a[] = {'a','b','c','\0','d','c','\0'};
	sizeof a == 7;
	puts(a); //abc就是有效字符
	字符串长度：有效字符的个数
	
字符串处理函数:
	字符串长度：
	#include <string.h>
	size_t strlen(const char *s);
	const char *s: 要求字符串长度的目标字符串(传递一个字符串的首地址)
	size_t: 目标字符串的有效长度	（在32位系统中size_t代表 unsigned int类型; 在64位系
									 统中size_t代表 long unsigned int类型）
	
	字符串的拷贝:
		有a,b两个字符串,把b字符串的内容拷贝a
	#include <string.h>
	实现字符串的完全拷贝
	char *strcpy(char *dest, const char *src);
	char *dest: 要拷贝的字符串的首地址
	const char *src: 要拷贝的目标字符串(被拷贝的字符串)
	char *: 返回要拷贝的字符串的首地址
	注意:
		第一个参数不能是字符串常量,只能是一个字符数组或malloc开辟堆空间的首地址
		第一个参数所在空间的大小应该大于第二个参数代表字符串的有效长度,否则会访问越界
	
	字符串部分拷贝函数：
	拷贝第二个参数代表字符串的前n个字符到第一个参数所带表的空间
    char *strncpy(char *dest, const char *src, size_t n);
	size_t n: 要拷贝目标字符串的前n位
	
	字符串拼接函数：
	char *strcat(char *dest, const char *src);
	char *dest：要拼接的第一个字符串首地址
	const char *src：要拼接的第二个字符串首地址
	char *：返回拼接后字符串的首地址
	注意:
		第一个参数不能是字符串常量,只能是一个字符数组或malloc开辟堆空间的首地址
		第一个参数所在空间的大小应该大于或等于两个字符串有效字符之和
	
	把第二个字符串前n个字符拼接在第一个字符串之后
    char *strncat(char *dest, const char *src, size_t n);
	
	字符串的比较:
	比较两个字符串是否完全一致(比较两个字符串的有效字符，不会改变两个字符串)
	int strcmp(const char *s1, const char *s2);
	返回值: 
		0 表示两个字符串完全一致
		非0: 两个字符串不同 
	
	比较两个字符串的前n个字符
    int strncmp(const char *s1, const char *s2, size_t n);	
	
	
作业:
	1、编写程序实现strlen的功能.
	
	2、编写程序实现strcat的功能.
	
	3、编写程序实现strcmp的功能.
	
	4、编写程序实现strncat的功能.
	
	5、编写程序实现字符串的循环移位
	
	6、编写程序实现删除字符串中指定的字符.
	
	7、编写程序实现将整型数据转换成字符串的功能 1234 -> "1234"
	
	8、编写程序实现登录.
	
	9、将一个字符串逆序.
	
	*10、删除目标字符串中指定的字符串 如"abcdefg" 删除"cde" -> "abfg"
	
	*11、删除字符串中所有重复的字符如:"abacdbec" -> "abcde"
	
	12、从键盘输入若干个整数，其值在0-4范围内，输入-1表示结束输入，统计各个数字的个数
	
	13、输入一行字符，统计大写字母、小写字母、数字、空格以及其它字符个数。

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
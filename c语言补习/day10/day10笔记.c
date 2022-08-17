递归函数:
	自己调自己
	
void fun(char ch)
{
	if(ch < 'D'){
		printf("%c\n", ch);
		fun(ch+1);
		printf("%c\n", ch);		
	}
	return;
}

int main()
{
	fun('A');
}

10! == 10*9*8*7...*1

int fun(int n)
{
	if(n == 1)
		return 1;
	 return n*fun(n-1);	
}

结构体:
	不同数据类型的集合
	一般形式:
	struct 结构体名{
		数据类型1 变量名1;
		数据类型2 变量名2;
		...
		数据类型n 变量名n;
	};
	struct 结构体名 变量名;
	
	struct worker{
		char name[20];
		int id;
		double salary;
	};
	struct worker boss = {"张三", 9527, 1.7};
	//boss.name = "小红"; //err
	strcpy(boss.name, "小红");
	boss.id = 9528;
	
	printf("name:%s\n", boss.name);
	
	struct worker *p = &boss;
	p->id = 9529;
	
	
	struct worker arr[10] = {0};
	scanf("%s %d %f", a[0].name, &(arr[0].id), &(arr[0].salary));
	
联合体(共用体) union
	union xx{
		char a;
		int b;
	};
	
	union xx a = 0;
	a.a = 'A';
	printf("%c \n", a.b);
	
内存管理:
	开辟空间:
		malloc
		int *p = malloc(100*sizeof(int))
	释放空间:
		free(p);
		
char *fun(char *p)
{
	char *q = malloc(100);
	strcpy(q, p);
	return q;
}

int main()
{
	char *p = "hello world";
	char *q = fun(p);
	puts(q);
	free(q);
}

void GetMem(char **p)
{
	*p = malloc(100);
}
	
int main()
{
	char *p = NULL;
	GetMem(&p);
	strcpy(p, "hello");
	puts(p);
	free(p);
}

void swap(char **sa, char **sb)
{
	char *t;
	t = *sa;
	*sa = *sb;
	*sb = t;
}

int main()
{
	char *pa = "abc";
	char *pb = "ABC";
	swap(&pa, &pb);
}

浮点数的存储:
	浮点数的二进制:
		分成两部分:
			整数部分: 2的整数次幂相加
			小数部分: 小数部分不断乘2取整
			3.14：
				整数部分: 11
				小数部分: 0.14*2 = 0.28 0.28*2 = 0.56 0.56*2 = 1.12 0.12*2 = 0.24...
						  .0010
			    11.0010
	浮点数在存储时先转化成2进制，在将二进制写成科学计数法
	1.10010 * 2^1
	浮点数在内存中占4字节32位，最高位表示符号其次8位表示指数位剩下的表示小数位
	0100 0000 0100 1000 1111 0101 1100 0010 
	1.100 1000 1111 0101 1100 0010 *2^1
	11.0010001111
	3.14
	
	8.5:
		1000
		1
	   1000.1
	   1.0001 * 2^3
	   0100 0001 0000 10000 ...
	   1.0001 * 2^3
	
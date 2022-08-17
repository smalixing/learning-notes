#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char buf[100] = "2022-7-21 11:40:30 hello";


	int a,b,c,d,e,f;

	char str[32] = {0};

	sscanf(buf, "%d-%d-%d %d:%d:%d %s", &a,&b,&c,&d,&e,&f,str);

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	printf("%s\n", str);

	return 0;
}

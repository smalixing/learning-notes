#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//线程函数
void *fun(void *arg)
{
#if 1	
	int n = (int)arg;

	printf("%d\n", n);

	pthread_exit(arg); //相当于return arg;
#endif

#if 0	
	char *p = (char *)arg;
	
	printf("%s\n", p);

	pthread_exit(arg);
#endif

}


int main(int argc, const char *argv[])
{
	pthread_t tid; //线程号

#if 1	
	int count = 100;

	pthread_create(&tid, NULL, fun, (void *)count);

	void *arg;

	pthread_join(tid, &arg);

	printf("%d  %d\n", count, (int)arg);
#endif


#if 0
	char buf[100] =  "hello";

	pthread_create(&tid, NULL, fun, (void *)buf);

	void *arg;

	pthread_join(tid, &arg);

	printf("%s %s\n", buf, (char *)arg);

#endif	
	while(1);

	return 0;
}

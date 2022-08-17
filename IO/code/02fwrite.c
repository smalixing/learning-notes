#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
	int m;
	float n;
	char ch;
};

int main(int argc, const char *argv[])
{
	struct A a = {10, 3.14, 'a'}; 

	printf("sizeof(a) = %d\n", sizeof(a));


	FILE *fp = fopen("./2.txt", "wb+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	fwrite(&a, sizeof(struct A) , 1, fp);

	rewind(fp);

	struct A b;

	fread(&b, sizeof(struct A), 1, fp);

	printf("%d %f %c\n", b.m, b.n, b.ch );

	fclose(fp);

	return 0;
}

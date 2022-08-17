#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monster{
	int ID;
	char name[32];
	char species[32];
	char type[32];
}MOS;

int createMonster(int n)
{
	MOS m1[n], m2[n];

	int i;
	for(i=0; i<n; i++)
	{
		printf("请输入第%d号怪兽信息: ", i+1);
	
		scanf("%d%s%s%s", &m1[i].ID, m1[i].name, m1[i].species, m1[i].type);
	}

	FILE *fp = fopen("Monster.txt", "wb+");
	if(fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	fwrite(m1, sizeof(MOS) , n, fp);

	rewind(fp);

	fread(m2, sizeof(MOS), n, fp);

	for(i=0; i<n; i++)
	{
		printf("%d %s %s %s\n", m2[i].ID, m2[i].name, m2[i].species, m2[i].type);
	}

	fclose(fp);
}

int main(int argc, const char *argv[])
{
	createMonster(3);

	return 0;
}

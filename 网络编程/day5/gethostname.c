/*===============================================
*   文件名称：gethostname.c
*   创 建 者：     
*   创建日期：2022年08月03日
*   描    述：
================================================*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{ 
    char name[32];
    if(-1 == gethostname(name, 32)){
        perror("gethostname");
        return -1;
    }
    printf("name: %s\n", name);
    strcpy(name, "ubuntu");
    
    if(-1 == sethostname(name, 32)){
        perror("sethostname");
        return -1;
    }

    if(-1 == gethostname(name, 32)){
        perror("gethostname");
        return -1;
    }
    printf("name: %s\n", name);
    strcpy(name, "Windows");
    return 0;
} 

#include <stdio.h>
#include <string.h>

int main(int argc,const char *argv[])
{

    int i = 0x11223344;
    char *ptr = (char *)&i;
    printf("%#x, %p\n",*ptr, ptr);
    printf("%#x, %p\n",*(ptr+1), ptr+1);
    printf("%#x, %p\n",*(ptr+2), ptr+2);
    printf("%#x, %p\n",*(ptr+3), ptr+3);
    return 0;
}








//小端：低字节存低地址
//大端：低字节存高地址
//网络字节序 采用大端存储

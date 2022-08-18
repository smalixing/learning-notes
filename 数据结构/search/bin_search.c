/*===============================================
*   文件名称：bin_search.c
*   创 建 者：     
*   创建日期：2022年07月18日
*   描    述：
================================================*/
#include <stdio.h>

typedef int data_t;

int bin_search(data_t *data, int size, data_t key)
{
    int mid, high, low;
    low = 0;
    high = size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == data[mid])
            return mid;
        else if (key > data[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{ 
    data_t data[10] = {3, 5, 9, 20, 56, 78, 89, 100, 123, 150};
    printf("pos: %d\n", bin_search(data, 10, 87));
    printf("pos: %d\n", bin_search(data, 10, 20));

    return 0;
} 

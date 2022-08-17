/*===============================================
*   文件名称：quick_sort.c
*   创 建 者：     
*   创建日期：2022年07月18日
*   描    述：
================================================*/
#include <stdio.h>

typedef int data_t;

void quick_sort(data_t data[], int low, int high)
{
    int i, j;
    data_t key;
    if (low < high)
    {
        i = low;
        j = high;
        key = data[i];
        while (i < j)
        {
            while ((i<j) && (key <= data[j]))
                j--;
            data[i] = data[j];
            while ((i<j) && (key >= data[i]))
                i++;
            data[j] = data[i];
        }
        data[i] = key;
        quick_sort(data, low, i-1);
        quick_sort(data, i+1, high);
    }
}

int main(int argc, char *argv[])
{ 
    data_t data[8] = {50, 36, 66, 76, 36, 12, 25, 96};
    quick_sort(data, 0, 7);
    int i;
    for (i = 0; i < 8; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
} 

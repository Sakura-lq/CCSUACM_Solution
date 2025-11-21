#include<stdio.h>

void swap(int *x , int *y)
{
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

int main(void)
{
    int x = 8, y = 2;
    swap(&x, &y);
    printf("%d %d", x, y);
    return 0;
}
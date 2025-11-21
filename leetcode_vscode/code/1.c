#include <stdio.h>

int main(void)
{
    int res = 1;
    for (int i = 1; i < 10; i++)
    {
        res++;
        res *= 2;
    }

    printf("%d\n", res);
    return 0;
}
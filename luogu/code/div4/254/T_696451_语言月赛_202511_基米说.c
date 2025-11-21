#include <stdio.h>

int main()
{
    long long x1, x2, x3;
    long long y1, y2, y3;

    scanf("%lld%lld%lld", &x1, &x2, &x3);
    scanf("%lld%lld%lld", &y1, &y2, &y3);

    long long res = x1 * y1 + x2 * y2 + x3 * y3;
    if (res == 0)
    {
        printf("Orthogonal\n");
    }
    else
    {
        printf("Non-Orthogonal\n");
    }

    return 0;
}
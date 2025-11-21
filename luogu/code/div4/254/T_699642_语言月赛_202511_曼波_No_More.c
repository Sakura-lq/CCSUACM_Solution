#include <stdio.h>

int main()
{
    long long n, m, r, c;
    long long x1, y1, x2, y2;

    scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

    long long res = ((x2 / r) - (x1 / r) + 1) * ((y2 / c) - (y1 / c) + 1);

    printf("%lld\n", res);

    return 0;
}
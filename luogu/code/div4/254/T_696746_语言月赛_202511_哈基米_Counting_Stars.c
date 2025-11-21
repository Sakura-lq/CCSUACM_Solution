#include <stdio.h>
#include <limits.h>

#define N 300007
#define MAX_KEY 400000

int main()
{
    long long n;
    scanf("%lld", &n);

    long long x[MAX_KEY];
    for (int i = 0; i < MAX_KEY; i++)
    {
        x[i] = INT_MAX;
    }

    long long mx = 0;
    for (long long i = 0; i < n; i++)
    {
        long long r, a, b;
        scanf("%lld%lld%lld", &r, &a, &b);
        long long key = a * 1000 + b;
        if (r < x[key])
        {
            x[key] = r;
        }
    }

    for (int i = 0; i < MAX_KEY; i++)
    {
        if (x[i] != INT_MAX && x[i] > mx)
        {
            mx = x[i];
        }
    }

    printf("%lld\n", mx);
    return 0;
}
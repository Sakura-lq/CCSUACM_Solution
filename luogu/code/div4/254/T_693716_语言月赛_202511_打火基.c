#include <stdio.h>

int main()
{
    long long n, x;
    long long res, ans;

    scanf("%lld", &n);
    scanf("%lld", &x);

    res = x & 1;
    ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld", &x);
        if (x & 1)
        { 
            if (res == 0)
            { 
                res = 1;
                ans++;
            }
        }
        else
        { 
            if (res == 1)
            { 
                res = 0;
                ans++;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define N 300007

long long lower_bound(long long arr[], long long len, long long x)
{
    long long left = 0, right = len - 1;
    long long res = len; 
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (arr[mid] >= x)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    long long n;
    scanf("%lld", &n);

    long long nums[N];
    long long idx[N + 1];
    idx[0] = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        nums[i - 1] = l;
        idx[i] = idx[i - 1] + r;
    }

    long long q, x;
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld", &x);
        long long pos = lower_bound(idx, n + 1, x);
        printf("%lld\n", nums[pos - 1]);
    }

    return 0;
}
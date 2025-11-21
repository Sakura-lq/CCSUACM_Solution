#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, opt, mod, mm, mx;
int t[80005];
int delta[80005];
int a[80005];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

int query(int l, int r)
{
    return getsum(r) - getsum(l - 1);
}

void solve()
{
    cin >> n >> opt >> mod >> mm >> mx;
    memset(delta, 0, sizeof(delta));
    memset(t, 0, sizeof(t));

    for (int i = 0; i < opt; i++)
    {
        char type;
        cin >> type;
        if (type == 'A')
        {
            int L, R, X;
            cin >> L >> R >> X;
            delta[L] += X;
            if (R + 1 <= n)
            {
                delta[R + 1] -= X;
            }
        }
        else if (type == 'Q')
        {
            int L, R;
            cin >> L >> R;
            int sum = 0, cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                sum += delta[j];
                a[j] = sum;
            }
            for (int j = L; j <= R; j++)
            {
                int val = a[j] * j % mod;
                if (val >= mm && val <= mx)
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += delta[i];
        a[i] = sum;
        int val = a[i] * i % mod;
        if (val >= mm && val <= mx)
        {
            update(i, 1);
        }
    }

    int f;
    cin >> f;
    while (f--)
    {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << endl;
    }
}

signed main()
{
    solve();
    return 0;
}

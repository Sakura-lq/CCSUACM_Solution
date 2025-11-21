#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[100005];
int m;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= m)
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
    int n, k;
    cin >> n >> k;

    int x;
    m = n + 1;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        update(i + 1, x);
    }

    int ans = 0;
    int mm = query(1, k);
    for (int i = k; i < n; i++)
    {
        int cur = query(i - k, i);
        if (mm < cur)
        {
            ans = i - k;
            mm = cur;
        }
    }

    cout << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
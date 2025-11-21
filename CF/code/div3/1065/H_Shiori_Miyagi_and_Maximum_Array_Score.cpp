#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int n, m;
int t[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    for (; k <= m - n + 1; k += lowbit(k))
    {
        t[k] = max(t[k], v);
    }
}

int query(int k)
{
    int res = 0;
    for (; k > 0; k -= lowbit(k))
    {
        res = max(res, t[k]);
    }

    return res;
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        t[i] = 0;
    }
}

void solve()
{
    cin >> n >> m;

    clear();
    auto f = [&](int b, int x) -> int
    {
        int ans = 0;
        while (!(x % b))
        {
            ans++;
            x /= b;
        }

        return ans;
    };

    for (int i = 2; i <= n; i++)
    {
        for (int j = (m - n + i) / i * i; j >= i; j -= i)
        {
            update(j - i + 1, query(j - i + 1) + f(i, j));
        }
    }

    cout << query(m - n + 1) << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
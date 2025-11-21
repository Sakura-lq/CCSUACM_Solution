#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    auto f = [&](auto &&f, vector<int> &a, int m, int k) -> int
    {
        if (k == 0)
        {
            return 0;
        }

        vector<vector<int>> b(2);
        for (int x : a)
        {
            int bit = (x >> (k - 1)) & 1;
            b[bit].push_back(x & ~(1LL << (k - 1)));
        }

        int mid = 1LL << (k - 1);

        if (m == (1LL << k))
        {
            if (!b[0].empty() && !b[1].empty())
            {
                return f(f, b[0], mid, k - 1) + f(f, b[1], mid, k - 1);
            }
            else
            {
                return 2 * f(f, a, mid, k - 1) + mid * mid;
            }
        }

        int ans = 0;
        if (!b[0].empty())
        {
            ans += f(f, b[0], min(m, mid), k - 1);
        }
        else
        {
            ans += f(f, a, min(m, mid), k - 1) + mid * min(m, mid);
        }

        if (m > mid)
        {
            if (!b[1].empty())
            {
                ans += f(f, b[1], m - mid, k - 1);
            }
            else
            {
                ans += f(f, a, m - mid, k - 1) + mid * (m - mid);
            }
        }

        return ans;
    };

    cout << f(f, a, m, 30) << endl;
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
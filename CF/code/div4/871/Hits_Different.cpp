#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int g[2000];

void init()
{
    g[0] = 0;
    for (int h = 1; h < 2000; h++)
    {
        g[h] = 1LL * h * (h + 1) / 2;
        if (g[h] > 1e6)
        {
            break;
        }
    }
}
void solve()
{
    i64 n;
    cin >> n;

    i64 res = 0;

    vector<bool> vis(1000010, false);
    int h = 0;
    for (int i = 1; i < 2000; i++)
    {
        if (g[i] >= n)
        {
            h = i;
            break;
        }
    }

    auto f = [&](auto &&f, i64 x, int new_h) -> i64
    {
        if (x < 1 || new_h < 1 || new_h < 1 || vis[x] || x > g[new_h] || x < g[new_h - 1] + 1)
        {
            return 0;
        }

        vis[x] = true;

        return x * x + f(f, x - new_h, new_h - 1) + f(f, x - new_h + 1, new_h - 1);
    };

    cout << f(f, n, h) << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
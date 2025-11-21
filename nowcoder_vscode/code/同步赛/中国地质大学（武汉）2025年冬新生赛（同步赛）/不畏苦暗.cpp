#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<array<int, 2>> f;

    for (int i = 1; i <= n; i++)
    {
        int x, v;
        cin >> x >> v;
        while (!f.empty())
        {
            auto [tx, tv] = f.back();
            if (v + tx - x >= tv)
            {
                f.pop_back();
            }
            else
            {
                break;
            }
        }
        if (!f.empty())
        {
            auto [tx, tv] = f.back();
            if (tv + tx - x >= v)
            {
                continue;
            }
        }
        f.push_back({x, v});
    }

    n = f.size();
    ans += f[0][1] * (f[0][1] - 1) / 2;
    ans += f[n - 1][1] * (f[n - 1][1] + 1) / 2;

    for (int i = 0; i < n - 1; i++)
    {
        auto [x1, v1] = f[i];
        auto [x2, v2] = f[i + 1];

        int z1 = x1 + v1, z2 = x2 - v2;
        if (z2 <= z1)
        {
            int z = (v1 + x1 - v2 + x2) / 2;
            int t = v1 + x1 - z;
            ans += (t + v1) * (v1 - t + 1) / 2;
            t = (v2 - 1) + z + 1 - (x2 - 1);
            ans += (t + v2 - 1) * (v2 - t) / 2;
        }
        else
        {
            ans += (v1 + 1) * v1 / 2;
            ans += (v2 - 1) * v2 / 2;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

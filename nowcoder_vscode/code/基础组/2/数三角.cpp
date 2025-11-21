#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int x1 = p[j].first - p[i].first;
                int y1 = p[j].second - p[i].second;
                int x2 = p[k].first - p[i].first;
                int y2 = p[k].second - p[i].second;
                int hh = x1 * y2 - y1 * x2;
                if (hh == 0)
                {
                    continue;
                }

                int d1 = (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
                int d2 = (p[i].first - p[k].first) * (p[i].first - p[k].first) + (p[i].second - p[k].second) * (p[i].second - p[k].second);
                int d3 = (p[j].first - p[k].first) * (p[j].first - p[k].first) + (p[j].second - p[k].second) * (p[j].second - p[k].second);
                int mx = max(d1, max(d2, d3));
                int sum = d1 + d2 + d3;
                if (mx > sum - mx)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
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

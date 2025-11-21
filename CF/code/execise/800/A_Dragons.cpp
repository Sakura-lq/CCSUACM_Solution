#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> d(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        d[i] = {x, y};
    }

    sort(d.begin(), d.end(), [&](const pair<int, int> &x, const pair<int, int> &y)
         { return x.first < y.first; });

    for (auto &[x, y] : d)
    {
        if (s > x)
        {
            s += y;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
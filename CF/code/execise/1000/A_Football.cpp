#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    cin.ignore();

    int mx = 0;
    string s, t;
    unordered_map<string, int> hash;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (mx < ++hash[s])
        {
            t = s;
        }
    }

    cout << t << endl;
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
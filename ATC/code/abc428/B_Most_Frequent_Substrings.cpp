#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<string, int> count;

    for (int i = 0; i <= n - k; i++)
    {
        string sub = s.substr(i, k);
        count[sub]++;
    }

    int mx = 0;
    for (auto &pair : count)
    {
        mx = max(mx, pair.second);
    }

    vector<string> t;
    for (auto &pair : count)
    {
        if (pair.second == mx)
        {
            t.push_back(pair.first);
        }
    }

    cout << mx << endl;
    for (int i = 0; i < t.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << t[i];
    }
    cout << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (char ch : s)
        {
            if (ch == '0')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        mp[a + b * 1e6]++;
    }
    vector<int> v;
    int res = 0;
    for (auto &[x, y] : mp)
    {
        if (y >= 2)
        {
            v.push_back(x);
            v.push_back(x);
        }
        else
        {
            v.push_back(x);
        }
    }
    n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mp.count(v[i] + v[j]))
            {
                res = res + mp[v[i] + v[j]];
                mp.erase(v[i] + v[j]);
            }
        }
    }
    cout << res << endl;
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
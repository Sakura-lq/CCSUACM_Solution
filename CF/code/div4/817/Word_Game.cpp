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

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    string a;
    set<string> sta, stb, stc;
    map<string, int> mp;

    for (int j = 0; j < n; j++)
    {
        cin >> a;
        sta.insert(a);
        mp[a]++;
    }

    for (int j = 0; j < n; j++)
    {
        cin >> a;
        stb.insert(a);
        mp[a]++;
    }

    for (int j = 0; j < n; j++)
    {
        cin >> a;
        stc.insert(a);
        mp[a]++;
    }

    for (auto &[s, cnt] : mp)
    {
        if (cnt == 1)
        {
            if (sta.count(s))
            {
                cnt1 += 3;
            }
            if (stb.count(s))
            {
                cnt2 += 3;
            }
            if (stc.count(s))
            {
                cnt3 += 3;
            }
        }
        else if (cnt == 2)
        {
            if (sta.count(s))
            {
                cnt1 += 1;
            }
            if (stb.count(s))
            {
                cnt2 += 1;
            }
            if (stc.count(s))
            {
                cnt3 += 1;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
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
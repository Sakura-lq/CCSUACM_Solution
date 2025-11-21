#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> seg;
    char pre = s[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == pre)
        {
            cnt++;
        }
        else
        {
            seg.push_back(cnt);
            pre = s[i];
            cnt = 1;
        }
    }
    seg.push_back(cnt);
    int m = seg.size();

    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        pref[i + 1] = pref[i] + seg[i];
    }

    int ans = 0;

    if (k == 1)
    {
        for (int i = 0; i < m; i++)
        {
            ans += seg[i] * (seg[i] + 1) / 2;
        }
    }
    else
    {
        if (m < k)
        {
            cout << 0 << endl;
            return;
        }
        for (int l = 0; l <= m - k; l++)
        {
            ans += seg[l] * seg[l + k - 1];
        }
    }

    cout << ans << endl;
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
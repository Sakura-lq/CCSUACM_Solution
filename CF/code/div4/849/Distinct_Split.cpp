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
    string s;
    cin >> n >> s;

    vector<int> cnt(26);
    vector<int> pref(n + 1);
    vector<int> suff(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + (cnt[s[i - 1] - 'a']++ ? 0 : 1);
    }

    cnt.assign(26, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + (cnt[s[i] - 'a']++ ? 0 : 1);
    }

    int mx = 0;
    for (int i = 0; i <= n; i++)
    {
        mx = max(mx, suff[i] + pref[i]);
    }

    cout << mx << endl;
    return;
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
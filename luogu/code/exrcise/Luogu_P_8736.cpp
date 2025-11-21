#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string name[1000005], dp[1000005], st[100005];

void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; s[i]; i++)
    {
        if (isupper(s[i]))
        {
            name[++cnt] = s[i];
        }
        else
        {
            name[cnt] += s[i];
        }
    }
    int len = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int pos = lower_bound(st + 1, st + 1 + len, name[i]) - st;
        len = max(len, pos);
        st[pos] = name[i];
        dp[pos] = dp[pos - 1] + name[i];
    }
    cout << dp[len];
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
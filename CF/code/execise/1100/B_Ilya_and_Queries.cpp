#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pre(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == s[i - 1]);
    }

    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << '\n';
    }
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
}

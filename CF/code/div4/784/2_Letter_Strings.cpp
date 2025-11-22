#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> cnt(12, vector<int>(12, 0));
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 2; ++j)
        {
            for (char c = 'a'; c <= 'k'; ++c)
            {
                if (c == s[j])
                {
                    continue;
                }
                string a = s;
                a[j] = c;
                ans += cnt[a[0] - 'a'][a[1] - 'a'];
            }
        }
        cnt[s[0] - 'a'][s[1] - 'a']++;
    }
    cout << ans << endl;
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
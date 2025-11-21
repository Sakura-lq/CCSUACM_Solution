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

    int cnt = 0;
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans = (ans + (i + 1) * cnt - sum) % mod;
            cnt++;
            sum += (i + 1);
            sum %= mod;
        }
    }

    cout << (ans % mod + mod) % mod << '\n';
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string m;

    cin >> m;

    string q = m;

    reverse(q.begin(), q.end());
    if (m == q)
    {
        cout << 0 << endl;
        return;
    }
    
    int n = m.length();

    string t = "";
    for (int i = 0; i < n; i++)
    {
        t += '9';
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += (t[i] - m[i]) + '0';
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
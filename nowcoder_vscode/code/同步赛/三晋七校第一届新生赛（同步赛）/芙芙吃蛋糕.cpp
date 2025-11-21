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
    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            int j = i + 1;
            while (j < n && s[j] == '#')
            {
                j++;
            }
            if (j < n && s[j] == ')')
            {
                ans = max(ans, j - i + 1);
            }
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << 1 << endl;
            return;
        }
    }

    cout << s.length() << endl;

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
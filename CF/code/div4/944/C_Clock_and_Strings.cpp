#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    for (int i = 1; i <= 12; i++)
    {
        if (i == a || i == b)
        {
            s += "a";
        }
        if (i == c || i == d)
        {
            s += "b";
        }
    }
    cout << (s == "abab" || s == "baba" ? "YES\n" : "NO\n");
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
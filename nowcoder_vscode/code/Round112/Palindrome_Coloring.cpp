#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

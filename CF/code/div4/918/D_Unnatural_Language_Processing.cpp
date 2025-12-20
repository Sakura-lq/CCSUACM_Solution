#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    string res = "";
    while (!s.empty())
    {
        int x;
        if (s.back() == 'a' || s.back() == 'e')
        {
            x = 2;
        }
        else
        {
            x = 3;
        }

        while (x--)
        {
            res += s.back();
            s.pop_back();
        }
        res += '.';
    }

    res.pop_back();
    reverse(res.begin(), res.end());

    cout << res << endl;
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
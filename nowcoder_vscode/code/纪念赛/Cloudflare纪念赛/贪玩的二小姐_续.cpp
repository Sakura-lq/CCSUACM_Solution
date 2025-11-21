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

    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    int q = 0;
    int res = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            q++;
        }
        else
        {
            q--;
        }

        if (q < 0)
        {
            res++;
            q += 2;
        }
    }

    res += q / 2;

    cout << res << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

vector<i64> f(i64 x)
{
    vector<i64> res;
    for (i64 i = 1; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
            {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

void solve()
{
    i64 w, h, d, n;
    cin >> w >> h >> d >> n;

    vector<i64> gd = f(n);
    for (i64 a : gd)
    {
        if (w % a != 0)
        {
            continue;
        }
        i64 k = n / a;
        vector<i64> gd1 = f(k);
        for (i64 b : gd1)
        {
            if (h % b != 0)
            {
                continue;
            }
            i64 c = k / b;
            if (d % c == 0)
            {
                cout << a - 1 << " " << b - 1 << " " << c - 1 << endl;
                return;
            }
        }
    }

    cout << -1 << endl;

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
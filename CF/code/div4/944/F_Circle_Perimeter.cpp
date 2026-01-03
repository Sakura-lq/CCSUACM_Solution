#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 r;
    cin >> r;
    i64 h = r;
    i64 res = 0;
    for (i64 i = 0; i <= r; i++)
    {
        while (i * i + h * h >= (r + 1) * (r + 1))
        {
            h--;
        }
        i64 temp = h;
        while (i * i + temp * temp >= r * r && temp > 0)
        {
            temp--;
            res++;
        }
    }

    cout << res * 4 << endl;
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
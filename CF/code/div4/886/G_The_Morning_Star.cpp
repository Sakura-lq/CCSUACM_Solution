#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, x, y;
    cin >> n;

    map<i64, i64> mp1, mp2, mp3, mp4;

    for (i64 i = 0; i < n; i++)
    {
        cin >> x >> y;
        mp1[x]++;
        mp2[y]++;
        mp3[x - y]++;
        mp4[x + y]++;
    }

    i64 res = 0;

    for (auto &[x, y] : mp1)
    {
        res += y * (y - 1);
    }
    for (auto &[x, y] : mp2)
    {
        res += y * (y - 1);
    }
    for (auto &[x, y] : mp3)
    {
        res += y * (y - 1);
    }
    for (auto &[x, y] : mp4)
    {
        res += y * (y - 1);
    }

    cout << res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
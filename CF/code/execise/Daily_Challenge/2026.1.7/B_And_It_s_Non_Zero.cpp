#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
int cnt[N][64] = {};

int init = []
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < __lg(i) + 1; j++)
        {
            cnt[i][j] = cnt[i - 1][j] + ((i >> j) & 1);
        }
    }
    return 0;
}();

void solve()
{
    int l, r;
    cin >> l >> r;

    int mx = 0;
    for (int i = 0; i < 64; i++)
    {
        mx = max(mx, cnt[r][i] - cnt[l - 1][i]);
    }

    cout << (r - l + 1) - mx << endl;
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
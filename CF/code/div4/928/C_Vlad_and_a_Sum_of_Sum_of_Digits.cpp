#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int res[N];

int init = []
{
    res[0] = 0;
    auto f = [&](int x) -> int
    {
        int cnt = 0;
        while (x)
        {
            cnt += (x % 10);
            x /= 10;
        }
        return cnt;
    };

    for (int i = 1; i < N; i++)
    {
        res[i] = res[i - 1] + f(i);
    }

    return 0;
}();

void solve()
{
    int x;
    cin >> x;
    cout << res[x] << endl;
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
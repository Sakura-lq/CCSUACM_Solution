#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    int x;
    if (n >= 100)
    {
        x = n / 100;
        n %= 100;
        cnt += x;
    }

    if (n >= 20)
    {
        x = n / 20;
        n -= x * 20;
        cnt += x;
    }

    if (n >= 10)
    {
        x = n / 10;
        n %= 10;
        cnt += x;
    }

    if (n >= 5)
    {
        x = n / 5;
        n %= 5;
        cnt += x;
    }

    cout << cnt + n << endl;
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
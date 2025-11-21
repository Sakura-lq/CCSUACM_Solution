#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int sum = 0;

    auto f = [&](int x) -> int
    {
        int k = 0;
        while (x > 1)
        {
            x >>= 1;
            ++k;
        }

        return k;
    };

    double base = log2(2024);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += f(x);
    }

    double ans = sum * 1.0 / base;

    cout << ceil(ans) << "\n";

    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
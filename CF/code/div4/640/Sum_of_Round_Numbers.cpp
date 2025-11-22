#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int x;
    cin >> x;

    int cnt = 0;
    int base = 1;
    vector<pair<int, int>> num;
    while (x)
    {
        int q = x % 10;
        if (q >= 1 && q <= 9)
        {
            cnt++;
            num.push_back({q, base});
        }
        base *= 10;
        x /= 10;
    }

    cout << cnt << endl;

    for(auto &[q, p] : num)
    {
        cout << q * p << ' ';
    }

    cout << endl;
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
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
    cin >> n;

    int res1 = 0, res2 = 0;
    for (int i = 0; i < n - 2; i++)
    {
        res1 ^= i;
        res2 ^= (i + 1);
    }

    int q = (1LL << 31) - 1;

    if (res1 != 0)
    {
        for (int i = 0; i < n - 2; i++)
        {
            cout << i << " ";
        }

        cout << q << " " << (q ^ res1) << endl;
    }
    else
    {
        for (int i = 1; i <= n - 2; i++)
        {
            cout << i << " ";
        }

        cout << q << " " << (q ^ res2) << endl;
    }
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
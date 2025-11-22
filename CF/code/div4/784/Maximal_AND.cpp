#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt1[31] = {0}; 

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = 0; j <= 30; j++)
        {
            if (x & (1 << j))
            {
                cnt1[j]++;
            }
        }
    }

    for (int i = 30; i >= 0 && k > 0; i--)
    {
        int d = n - cnt1[i];
        if (k >= d)
        {
            k -= d;
            cnt1[i] = n;
        }
    }

    int res = 0;
    for (int i = 0; i <= 30; i++)
    {
        if (cnt1[i] == n)
        {
            res += (1 << i);
        }
    }

    cout << res << endl;
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
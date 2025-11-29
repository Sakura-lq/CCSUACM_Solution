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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> p(n - 1, 0);
    for (int j = 0; j < n - 1; j++)
    {
        if (a[j] < 2 * a[j + 1])
        {
            p[j] = 1;
        }
    }

    int res = 0;
    int len = 0;

    for (int j = 0; j < n - 1; j++)
    {
        if (p[j] == 1)
        {
            len++;
            if (len >= k)
            {
                res++;
            }
        }
        else
        {
            len = 0;
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
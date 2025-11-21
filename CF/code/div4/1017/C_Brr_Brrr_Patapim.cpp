#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> dui(2 * n + 1);
    vector<int> cnt(2 * n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            dui[i + j] = x;
            cnt[x]++;
        }
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (cnt[i] == 0)
        {
            dui[1] = i;
        }
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        cout << dui[i] << (i == 2 * n ? '\n' : ' ');
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
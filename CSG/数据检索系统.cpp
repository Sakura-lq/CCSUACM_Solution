#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int mod_pow(int x, int e, int mod)
{
    if (mod == 1)
    {
        return 0;
    }
    int res = 1;
    int base = x % mod;
    while (e > 0)
    {
        if (e & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        e >>= 1;
    }
    return res;
}

void solve()
{
    int n, k, m, q;
    cin >> n >> k >> m >> q;

    vector<int> bitset(n, 0);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= k; j++)
        {
            bitset[mod_pow(x, j, n)] = 1;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int y;
        cin >> y;
        bool ok = true;
        for (int j = 1; j <= k; j++)
        {
            if (bitset[mod_pow(y, j, n)] == 0)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

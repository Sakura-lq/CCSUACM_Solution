#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

const int MAXN = 100000;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    vector<int> freq(n + 1, 0);

    for (int i = 2; i * i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                vis[j] = 1;
            }
        }
    }

    for (int c = 4; c <= n; c++)
    {
        if (vis[c])
        {
            for (int x = c; x <= n; x += c)
            {
                cnt[x]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] <= n)
        {
            freq[cnt[i]]++;
        }
    }

    while (m--)
    {
        int k;
        cin >> k;
        if (k <= n)
        {
            cout << freq[k] << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
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
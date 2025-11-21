#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 505; 

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m, '.'));

    for (int j = 0; j < m; ++j)
    {
        int pos = j % 4;
        if (pos == 0 || pos == 2 || j == m - 1)
        {
            for (int i = 0; i < n; ++i)
            {
                g[i][j] = 'x';
            }
        }
        else if (pos == 1)
        {
            g[n - 1][j] = 'x';
        }
        else if (pos == 3)
        {
            g[0][j] = 'x';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << g[i][j];
        }
        cout << '\n';
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
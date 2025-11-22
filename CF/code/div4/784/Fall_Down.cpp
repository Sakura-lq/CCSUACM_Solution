#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[j][i] == '*')
            {
                cnt++;
                g[j][i] = '.';
            }
            else if (g[j][i] == 'o')
            {
                for (int k = 1; k <= cnt; k++)
                {
                    g[j - k][i] = '*';
                }
                cnt = 0;
            }
        }

        for (int k = 1; k <= cnt; k++)
        {
            g[n - k][i] = '*';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << g[i][j];
        }
        cout << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n';
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

void solve()
{
    int n, m;
    cin >> n >> m;
    char g[n][m];
    int id[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            id[i][j] = 0;
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '*')
            {
                vector<pair<int, int>> x, y;
                if (i > 0 && g[i - 1][j] == '*')
                {
                    x.emplace_back(i - 1, j);
                }
                if (i < n - 1 && g[i + 1][j] == '*')
                {
                    x.emplace_back(i + 1, j);
                }
                if (j > 0 && g[i][j - 1] == '*')
                {
                    y.emplace_back(i, j - 1);
                }
                if (j < m - 1 && g[i][j + 1] == '*')
                {
                    y.emplace_back(i, j + 1);
                }
                if (x.size() == 1 && y.size() == 1)
                {
                    if (id[i][j] == 0)
                    {
                        id[i][j] = cnt;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    if (id[x[0].first][x[0].second] == 0)
                    {
                        id[x[0].first][x[0].second] = cnt;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    if (id[y[0].first][y[0].second] == 0)
                    {
                        id[y[0].first][y[0].second] = cnt;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        return;
                    }
                    cnt++;
                }
                else if (x.size() > 1 || y.size() > 1)
                {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '*')
            {
                if (id[i][j] == 0)
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    for (int x = 0; x < 3; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (0 <= i + dx[x] && i + dx[x] < n && 0 <= j + dy[y] && j + dy[y] < m)
                            {
                                if (id[i + dx[x]][j + dy[y]] != id[i][j] && id[i + dx[x]][j + dy[y]] != 0)
                                {
                                    cout << "NO" << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "YES" << endl;

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
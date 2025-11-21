#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 3005;

int h, w;
vector<vector<char>> g(N, vector<char>(N));
vector<vector<int>> d(N, vector<int>(N, -1));
int dis[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve()
{
    cin >> h >> w;
    int sx = -1, sy = -1, tx = -1, ty = -1;

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> g[i][j];
            if (g[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (g[i][j] == 'T')
            {
                tx = i;
                ty = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 0;

    auto f = [](int x, int y) -> bool
    {
        return x >= 0 && x < h && y >= 0 && y < w && (g[x][y] == 'S' || g[x][y] == 'T' || g[x][y] == '.');
    };
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == tx && y == ty)
        {
            cout << d[x][y] << endl;
            return;
        }

        for (auto [dx, dy] : dis)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (f(nx, ny) && d[nx][ny] == -1)
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                if (nx == tx && ny == ty)
                {
                    cout << d[nx][ny] << endl;
                    return;
                }
            }
        }

        for (auto [dx, dy] : dis)
        {
            int mid_x = x + dx;
            int mid_y = y + dy;
            int nx = x + 2 * dx;
            int ny = y + 2 * dy;
            if (mid_x >= 0 && mid_x < h && mid_y >= 0 && mid_y < w && g[mid_x][mid_y] == 'M' &&
                f(nx, ny) && d[nx][ny] == -1)
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
                if (nx == tx && ny == ty)
                {
                    cout << d[nx][ny] << endl;
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
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
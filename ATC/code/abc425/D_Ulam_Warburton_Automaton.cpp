#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int H, W;
vector<vector<char>> cell;
vector<pair<int, int>> dirt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve()
{
    cin >> H >> W;
    cin.ignore();

    cell.resize(H);
    for (int i = 0; i < H; ++i)
    {
        string s;
        cin >> s;
        cell[i] = vector<char>(s.begin(), s.end());
    }

    vector<pair<int, int>> T;

    auto check = [&](int x, int y) -> bool
    {
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    auto f_cnt = [&](int x, int y) -> int
    {
        int cnt = 0;
        for (auto [dx, dy] : dirt)
        {
            int nx = dx + x;
            int ny = dy + y;
            if (check(nx, ny) && cell[nx][ny] == '#')
            {
                cnt++;
            }
        }

        return cnt;
    };

    for (int i = 0; i < H * W; i++)
    {
        if (i == 0)
        {
            T.clear();
            for (int x = 0; x < H; x++)
            {
                for (int y = 0; y < W; y++)
                {
                    if (cell[x][y] == '.' && f_cnt(x, y) == 1)
                    {
                        T.emplace_back(x, y);
                    }
                }
            }
        }
        else
        {
            vector<pair<int, int>> nT;
            for (auto [x, y] : T)
            {
                for (auto [dx, dy] : dirt)
                {
                    int nx = dx + x;
                    int ny = dy + y;

                    if (check(nx, ny) && cell[nx][ny] == '.' && f_cnt(nx, ny) == 1)
                    {
                        nT.emplace_back(nx, ny);
                    }
                }
            }

            T = move(nT);
        }

        if (T.empty())
        {
            break;
        }

        for (auto [x, y] : T)
        {
            cell[x][y] = '#';
        }
    }

    int ans = 0;
    for (int x = 0; x < H; ++x)
    {
        for (int y = 0; y < W; ++y)
        {
            if (cell[x][y] == '#')
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return;
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
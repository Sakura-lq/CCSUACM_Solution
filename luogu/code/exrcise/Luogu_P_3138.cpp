#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int t[1005][1005];
int nx, ny;

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int y, int v)
{
    for (int i = x; i <= nx; i += lowbit(i))
    {
        for (int j = y; j <= ny; j += lowbit(j))
        {
            t[i][j] += v;
        }
    }
}

int getsum(int x, int y)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            res += t[i][j];
        }
    }

    return res;
}

int query(int x1, int y1, int x2, int y2)
{
    return getsum(x2, y2) - getsum(x2, y1 - 1) - getsum(x1 - 1, y2) + getsum(x1 - 1, y1 - 1);
}

void solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    set<int> x_hash;
    set<int> y_hash;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    for (auto &[x, y] : points)
    {
        x_hash.insert(x);
        y_hash.insert(y);
    }

    vector<int> x_points(x_hash.begin(), x_hash.end());
    vector<int> y_points(y_hash.begin(), y_hash.end());

    auto getx = [&](int x) -> int
    {
        return lower_bound(x_points.begin(), x_points.end(), x) - x_points.begin() + 1;
    };

    auto gety = [&](int y) -> int
    {
        return lower_bound(y_points.begin(), y_points.end(), y) - y_points.begin() + 1;
    };

    int mx = x_points.back();
    int my = y_points.back();
    nx = x_points.size();
    ny = y_points.size();

    for (auto &p : points)
    {
        int x = getx(p.first);
        int y = gety(p.second);
        update(x, y, 1);
    }

    int ans = 1e9;
    for (int i = 1; i < nx; i++)
    {
        for (int j = 1; j < ny; j++)
        {
            ans = min(ans, max({query(1, 1, i, j), query(i + 1, 1, nx, j), query(1, j + 1, i, ny), query(i + 1, j + 1, nx, ny)}));
        }
    }

    cout << ans << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int m, K;
vector<vector<int>> t;

int lowbit(int x)
{
    return x & -x;
}

void update(int row, int k, int v)
{
    while (k <= m)
    {
        t[row][k] += v;
        k += lowbit(k);
    }
}

int getsum(int row, int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[row][k];
        k -= lowbit(k);
    }
    return res;
}

int rangeSum(int row, int l, int r)
{
    return getsum(row, r) - getsum(row, l - 1);
}

void solve()
{
    int n;
    cin >> n >> K;
    m = K;
    t.assign(K + 1, vector<int>(K + 1, 0));

    vector<int> req(n);
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
    }

    int center = (K + 1) / 2;

    for (int r = 0; r < n; r++)
    {
        int len = req[r];
        int best_cost = LLONG_MAX;
        int best_x = -1, best_l = -1, best_r = -1;

        for (int x = 1; x <= K; x++)
        {
            for (int yl = 1; yl + len - 1 <= K; yl++)
            {
                int yr = yl + len - 1;

                if (rangeSum(x, yl, yr) > 0)
                {
                    continue;
                }

                int cost = abs(x - center) * len;
                for (int y = yl; y <= yr; y++)
                {
                    cost += abs(y - center);
                }

                if (cost < best_cost ||
                    (cost == best_cost && x < best_x) ||
                    (cost == best_cost && x == best_x && yl < best_l))
                {
                    best_cost = cost;
                    best_x = x;
                    best_l = yl;
                    best_r = yr;
                }
            }
        }

        if (best_x == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << best_x << " " << best_l << " " << best_r << endl;
            for (int y = best_l; y <= best_r; y++)
            {
                update(best_x, y, 1);
            }
        }
    }
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

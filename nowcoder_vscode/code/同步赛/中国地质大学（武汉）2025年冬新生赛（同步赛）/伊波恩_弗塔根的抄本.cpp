#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

struct DSU
{
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 1)
    {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return;
        }
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    DSU dsu(n + m);

    vector<pair<int, int>> e(k);

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, n + y);
        e.emplace_back(x, n + y);
    }

    unordered_map<int, int> cntL, cntR, cntE;

    for (int i = 1; i <= n + m; i++)
    {
        int x = dsu.find(i);
        if (i <= n)
        {
            cntL[x]++;
        }
        else
        {
            cntR[x]++;
        }
    }

    for (auto &x : e)
    {
        cntE[dsu.find(x.first)]++;
    }

    int res = 0;

    for (auto &[f, _] : cntL)
    {
        res += (cntL[f] * cntR[f] - cntE[f]);
    }

    cout << (res % 2 == 1 ? "Arkham" : "Yightek") << endl;
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

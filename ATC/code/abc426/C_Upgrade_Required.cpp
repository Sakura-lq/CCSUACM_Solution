#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

struct DSU
{
    vector<int> fa;
    DSU(int n) : fa(n + 2)
    {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x)
    {
        if (fa[x] != x)
        {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    void erase(int x)
    {
        fa[x] = find(x + 1);
    }
};

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> X(Q), Y(Q);
    for (int i = 0; i < Q; ++i)
    {
        cin >> X[i] >> Y[i];
    }

    DSU dsu(N);
    vector<int> cnt(N + 2, 1);

    for (int i = 0; i < Q; ++i)
    {
        int x = X[i], y = Y[i];
        int up = 0;

        int cur = dsu.find(1);
        while (cur <= x)
        {
            up += cnt[cur];
            cnt[y] += cnt[cur];
            cnt[cur] = 0;
            dsu.erase(cur);
            cur = dsu.find(cur);
        }

        cout << up << '\n';
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
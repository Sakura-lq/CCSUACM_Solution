#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Q
{
    int l, r, id;
    bool operator<(const Q &other) const
    {
        int block_size = 450;
        if (l / block_size != other.l / block_size)
        {
            return l / block_size < other.l / block_size;
        }
        return ((l / block_size) & 1) ? (r > other.r) : (r < other.r);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<Q> qur(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qur[i].l >> qur[i].r;
        qur[i].id = i;
    }

    sort(qur.begin(), qur.end());

    vector<int> cnt(1e5 + 10, 0);
    vector<vector<int>> ans(q);
    int l = 1, r = 0;

    auto add = [&](int x) -> void
    {
        cnt[x]++;
    };
    auto remove = [&](int x) -> void
    {
        cnt[x]--;
    };

    for (auto qu : qur)
    {
        while (r < qu.r)
        {
            add(a[++r]);
        }
        while (r > qu.r)
        {
            remove(a[r--]);
        }
        while (l < qu.l)
        {
            remove(a[l++]);
        }
        while (l > qu.l)
        {
            add(a[--l]);
        }

        int len = qu.r - qu.l + 1;
        int th = len / 3;

        vector<int> temp;
        set<int> vis;
        for (int i = qu.l; i <= qu.r; i++)
        {
            if (cnt[a[i]] > th && !vis.count(a[i]))
            {
                temp.push_back(a[i]);
                vis.insert(a[i]);
            }
        }
        sort(temp.begin(), temp.end());
        ans[qu.id] = temp;
    }

    for (auto &v : ans)
    {
        if (v.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}

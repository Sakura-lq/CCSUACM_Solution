#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<vector<int>> re;
    int max_k = 0;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        max_k = max(max_k, k);
        g[i].assign(k, 0);

        for (int j = 0; j < k; j++)
        {
            cin >> g[i][j];
            if (re.size() == j)
            {
                re.push_back({});
            }
            re[j].push_back(i);
        }
    }

    vector<int> len_mm(max_k);
    vector<int> rank(n, -1);

    for (int i = max_k - 1; i >= 0; i--)
    {
        vector<array<int, 3>> cur;
        for (int &x : re[i])
        {
            cur.push_back({g[x][i], rank[x], x});
        }

        sort(cur.begin(), cur.end());

        len_mm[i] = cur[0][2];

        int rk = 0;
        for (auto &x : cur)
        {
            rank[x[2]] = rk++;
        }
    }

    vector<int> ans;
    while (ans.size() < max_k)
    {
        int temp = ans.size();
        auto &v = g[len_mm[temp]];
        for (int i = temp; i < v.size(); i++)
        {
            ans.push_back(v[i]);
        }
    }

    for (auto &x : ans)
    {
        cout << x << ' ';
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    map<pair<int, int>, int> ans;
    vector<pair<int, int>> p;
    vector<vector<int>> q(n);
    for (int i = n; i >= 1; i--)
    {
        for (int j = n - i + 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (j == n - i + 1)
                continue;
            if (((n - i + 1) ^ j) == temp)
            {
                ans[{n - i + 1, j}] = 1;
            }
            if (temp == 0)
            {
                p.push_back({n - i + 1, j});
            }
        }
    }
    int m = p.size();
    for (int i = 0; i < m; i++)
    {
        int x = p[i].first, y = p[i].second;
        vector<int> a;
        vector<int> b;
        for (int j = 1; j <= n; j++)
        {
            if (ans[{x, j}] == 1 || ans[{j, x}] == 1)
            {
                a.push_back(j);
            }
        }
        for (int k = 1; k <= n; k++)
        {
            if (ans[{y, k}] == 1 || ans[{k, y}] == 1)
            {
                b.push_back(k);
            }
        }
        int a1 = a.size(), b1 = b.size();
        for (int j = 0; j < a1; j++) {
            for (int k = 0; k < b1; k++) {
                if(ans[{j , k}] == 1)
                    ans[{j, k}] = 0;
                if(ans[{k , j}] == 1)
                    ans[{k, j}] = 0;
            }
        }
    }
    for (auto [x, y] : ans)
    {
        if (y == 1)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }

    unordered_map<int, pair<int, int>> hash;

    for (int k = 0; k < n; k++)
    {
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[P[i] + P[(i + k) % n]]++;
        }
        for (auto &p : cnt)
        {
            int sum = p.first, c = p.second;
            if (!hash.count(sum) || c > hash[sum].first || (c == hash[sum].first && k < hash[sum].second))
            {
                hash[sum] = {c, k};
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (hash.count(x))
        {
            cout << hash[x].second << endl;
        }
        else
        {
            cout << 0 << endl;
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
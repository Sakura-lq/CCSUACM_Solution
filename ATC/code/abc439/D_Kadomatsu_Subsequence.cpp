#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    map<i64, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        i64 a;
        cin >> a;
        pos[a].push_back(i);
    }

    i64 ans = 0;
    for (auto &[x5, j_pos] : pos)
    {
        if (x5 % 5 != 0)
        {
            continue;
        }

        i64 x7 = x5 / 5 * 7;
        i64 x3 = x5 / 5 * 3; 

        auto it7 = pos.find(x7);
        auto it3 = pos.find(x3);
        if (it7 == pos.end() || it3 == pos.end())
        {
            continue;
        }

        auto &i_pos = it7->second; 
        auto &k_pos = it3->second; 

        for (int j : j_pos)
        {
            i64 cnt_i_left = lower_bound(i_pos.begin(), i_pos.end(), j) - i_pos.begin();
            i64 cnt_k_left = lower_bound(k_pos.begin(), k_pos.end(), j) - k_pos.begin();
            ans += cnt_i_left * cnt_k_left;

            i64 cnt_i_right = i_pos.end() - upper_bound(i_pos.begin(), i_pos.end(), j);
            i64 cnt_k_right = k_pos.end() - upper_bound(k_pos.begin(), k_pos.end(), j);
            ans += cnt_i_right * cnt_k_right;
        }
    }

    cout << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

vector<array<int, 26>> cnts;
array<i64, 26> sums;
vector<array<i64, 26>> sum;

void solve()
{

    int n, m;
    cin >> n >> m;
    cnts.resize(n);
    sums.fill(0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        array<int, 26> cnt = {0};
        for (char c : s)
        {
            cnt[c - 'A']++;
        }
        cnts[i] = cnt;
        for (int c = 0; c < 26; ++c)
        {
            sums[c] += cnt[c];
        }
    }

    sum.resize(n);
    for (int l = 0; l < n; ++l)
    {
        for (int c = 0; c < 26; ++c)
        {
            sum[l][c] = sums[c] - cnts[l][c];
        }
    }

    vector<i64> res(n);
    for (int l = 0; l < n; ++l)
    {
        bool flag = true;
        for (int c = 0; c < 26; ++c)
        {
            if (m * sum[l][c] < cnts[l][c])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << " \n"[l == n - 1];
            continue;
        }

        i64 mx = m;
        for (int c = 0; c < 26; ++c)
        {
            if (sum[l][c] == 0)
            {
                continue;
            }
            mx = min(mx, (m * sum[l][c] - cnts[l][c]) / sum[l][c]);
        }

        cout << mx << " \n"[l == n - 1];
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
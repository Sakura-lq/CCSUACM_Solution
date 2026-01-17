#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
const i64 inf = -(1LL << 60);

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> v[i];
    }

    vector<vector<i64>> pref(n + 2, vector<i64>(m + 1, inf));
    pref[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            pref[i][j] = pref[i - 1][j];
            if (j >= p[i] && pref[i - 1][j - p[i]] != inf)
            {
                pref[i][j] = max(pref[i][j], pref[i - 1][j - p[i]] + v[i]);
            }
        }
    }

    i64 mxx = 0;
    for (int i = 0; i <= m; i++)
    {
        mxx = max(mxx, pref[n][i]);
    }

    vector<vector<i64>> suf(n + 2, vector<i64>(m + 1, inf));
    suf[n + 1][0] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            suf[i][j] = suf[i + 1][j];
            if (j >= p[i] && suf[i + 1][j - p[i]] != inf)
            {
                suf[i][j] = max(suf[i][j], suf[i + 1][j - p[i]] + v[i]);
            }
        }
    }

    // vector<vector<i64>> sufmx(n + 2, vector<i64>(m + 1, inf));
    for (int i = 1; i <= n + 1; i++)
    {
        i64 mx = inf;
        for (int j = 0; j <= m; j++)
        {
            mx = max(mx, suf[i][j]);
            suf[i][j] = mx;
        }
    }

    string ans;
    for (int i = 1; i <= n; i++)
    {
        bool flag1 = false;
        bool flag2 = false;

        for (int j = 0; j <= m; j++)
        {
            if (pref[i - 1][j] == inf || m - j - p[i] < 0)
            {
                continue;
            }
            if (pref[i - 1][j] + v[i] + suf[i + 1][m - j - p[i]] == mxx)
            {
                flag1 = true;
                break;
            }
        }

        for (int j = 0; j <= m; j++)
        {
            if (pref[i - 1][j] == inf)
            {
                continue;
            }
            if (pref[i - 1][j] + suf[i + 1][m - j] == mxx)
            {
                flag2 = true;
                break;
            }
        }

        if (flag1 && flag2)
        {
            ans.push_back('B');
        }
        else if (flag1)
        {
            ans.push_back('A');
        }
        else
        {
            ans.push_back('C');
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

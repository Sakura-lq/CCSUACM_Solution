#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

tuple<int, int, int> pm(char c, int cnt)
{
    int dr = 0, dc = 0;
    if (c == 'U')
    {
        dr = -1;
    }
    else if (c == 'D')
    {
        dr = 1;
    }
    else if (c == 'L')
    {
        dc = -1;
    }
    else if (c == 'R')
    {
        dc = 1;
    }
    return {dr, dc, cnt};
}

void solve()
{
    int rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    int N, M, L;
    cin >> N >> M >> L;

    vector<tuple<int, int, int>> ss;
    for (int i = 0; i < M; ++i)
    {
        char c;
        int a;
        cin >> c >> a;
        ss.emplace_back(pm(c, a));
    }

    vector<tuple<int, int, int>> ts;
    for (int i = 0; i < L; ++i)
    {
        char c;
        int b;
        cin >> c >> b;
        ts.emplace_back(pm(c, b));
    }

    int ans = 0;
    int tot = 0;
    int ps = 0, pt = 0;

    while (tot < N && ps < M && pt < L)
    {
        auto [dsr, dsc, cs] = ss[ps];
        auto [dtr, dtc, ct2] = ts[pt];

        int rm = N - tot;
        int k = min({cs, ct2, rm});

        int dr = rt - ra;
        int dc = ct - ca;
        int ddr = dsr - dtr;
        int ddc = dsc - dtc;

        if (ddr == 0 && ddc == 0)
        {
            if (dr == 0 && dc == 0)
            {
                ans += k;
            }
        }
        else
        {
            bool flag = 0;
            int t = -1;
            if (ddr == 0)
            {
                if (dr == 0 && dc % ddc == 0)
                {
                    t = -dc / ddc;
                    flag = (t >= 1 && t <= k);
                }
            }
            else if (ddc == 0)
            {
                if (dc == 0 && dr % ddr == 0)
                {
                    t = -dr / ddr;
                    flag = (t >= 1 && t <= k);
                }
            }
            else
            {
                if (dr % ddr == 0 && dc % ddc == 0)
                {
                    int t1 = -dr / ddr, t2 = -dc / ddc;
                    if (t1 == t2)
                    {
                        t = t1;
                        flag = (t >= 1 && t <= k);
                    }
                }
            }
            if (flag)
            {
                ans += 1;
            }
        }

        tot += k;
        rt += dsr * k;
        ct += dsc * k;
        ra += dtr * k;
        ca += dtc * k;

        ss[ps] = {dsr, dsc, cs - k};
        if (get<2>(ss[ps]) == 0)
        {
            ps++;
        }
        ts[pt] = {dtr, dtc, ct2 - k};
        if (get<2>(ts[pt]) == 0)
        {
            pt++;
        }
    }

    cout << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
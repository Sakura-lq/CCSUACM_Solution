#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n, m, k, h;
vector<int> a;

string toString(__int128 x)
{
    if (x == 0)
    {
        return "0";
    }
    bool neg = false;
    if (x < 0)
    {
        neg = true;
        x = -x;
    }
    string s;
    while (x > 0)
    {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    if (neg)
    {
        s.push_back('-');
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve()
{
    cin >> n >> m >> k >> h;
    a.resize(n);
    int mx = 0;
    long long mm = (1LL << 60);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mm = min(mm, (long long)a[i]);
    }

    auto check = [&](long long mid) -> bool
    {
        __int128 n1 = 0;
        __int128 fh = 0;
        vector<int> re;

        for (int v : a)
        {
            if (v >= mid)
            {
                continue;
            }
            __int128 d = (__int128)mid - v;
            n1 += d;
            fh += d / h;
            int r = (int)(d % h);
            if (r)
            {
                re.push_back(r);
            }
        }

        if (n1 <= m)
        {
            return true;
        }

        if (fh >= k)
        {
            __int128 af = n1 - (__int128)k * h;
            return af <= m;
        }
        else
        {
            __int128 af = n1 - fh * h;
            __int128 rk = (__int128)k - fh;
            if (rk <= 0)
                return af <= m;

            if ((__int128)re.size() <= rk)
            {
                __int128 sumr = 0;
                for (int r : re)
                {
                    sumr += r;
                }
                af -= sumr;
                return af <= m;
            }
            else
            {
                sort(re.begin(), re.end(), greater<int>());
                __int128 sa = 0;
                for (int i = 0; i < (int)rk; ++i)
                {
                    sa += re[i];
                }
                af -= sa;
                return af <= m;
            }
        }
    };

    long long L = mm, R = mx + m + k * (long long)h, ans = L;
    while (L <= R)
    {
        long long mid = L + (R - L) / 2;
        if (check(mid))
        {
            ans = mid;
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

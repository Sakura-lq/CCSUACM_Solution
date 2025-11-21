#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

struct BIT
{
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int x, int v)
    {
        for (; x <= n; x += x & -x)
        {
            t[x] += v;
        }
    }
    int sum(int x)
    {
        int s = 0;
        for (; x > 0; x -= x & -x)
        {
            s += t[x];
        }
        return s;
    }
};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;

    BIT cntbit(n), sumbit(n);
    int res = 0, sum = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int pos = i + 1;
            ans = (ans + pos * res - sum) % mod;
            res++;
            sum += pos;
            cntbit.add(pos, 1);
            sumbit.add(pos, pos);
        }
    }

    cout << (ans % mod + mod) % mod << '\n';

    while (m--)
    {
        int q, pos;
        cin >> q >> pos;

        int cntL = cntbit.sum(pos - 1);
        int sumL = sumbit.sum(pos - 1);
        int cntR = res - cntL;
        int sumR = sum - sumL;

        if (q == 1)
        {
            int tot = (pos * cntL - sumL) + (sumR - pos * cntR);
            ans = (ans + tot) % mod;

            cntbit.add(pos, 1);
            sumbit.add(pos, pos);
            res++;
            sum += pos;
            s[pos - 1] = '1';
        }
        else
        {
            cntR--;
            sumR -= pos;
            int tot = (pos * cntL - sumL) + (sumR - pos * cntR);
            ans = (ans - tot) % mod;

            cntbit.add(pos, -1);
            sumbit.add(pos, -pos);
            res--;
            sum -= pos;
            s[pos - 1] = '0';
        }

        cout << (ans % mod + mod) % mod << endl;
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
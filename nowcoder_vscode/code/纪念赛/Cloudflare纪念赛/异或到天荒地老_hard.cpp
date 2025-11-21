#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int ksm(int n, int m)
{
    int res = 1;
    while (m)
    {
        if (m & 1)
        {
            res = res * n % mod;
        }
        n = n * n % mod;
        m = m >> 1;
    }
    return res;
}
void solve()
{
    for (int i = 1; i <= 100; i++)
    {
        int n = i, m = i, res = 0;
        do
        {
            m = m ^ (m >> 1);
            res++;
        } while (n != m);
        if (ksm(2, log2(log(i) + 1)) == res)
        {
        }
        else
        {
            cout << 1;
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
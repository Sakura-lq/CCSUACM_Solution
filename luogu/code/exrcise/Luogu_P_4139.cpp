#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX_P = 1e7 + 10;

int phi[MAX_P];

void init_phi()
{
    for (int i = 0; i < MAX_P; ++i)
    {
        phi[i] = i;
    }
    for (int i = 2; i < MAX_P; ++i)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < MAX_P; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int ksm(int a, int b, int mod)
{
    int res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int euler(int x)
{
    if (x < 3)
    {
        return 0;
    }
    int ph = phi[x];
    int exp = euler(ph);
    return ksm(2, exp + ph, x);
}

void solve()
{
    int p;
    cin >> p;
    cout << euler(p) << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_phi();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
int inv[N], fact[N];

int ksm(int a, int b, int m)
{
    int res = 1;
    b %= m;

    while (b)
    {
        if (b & 1)
        {
            res = res * a % m;
        }

        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void init(int p)
{
    fact[0] = 1;
    for (int i = 1; i < p; i++)
    {
        fact[i] = fact[i - 1] * i % p;
    }

    inv[p - 1] = ksm(fact[p - 1], p - 2, p);

    for (int i = p - 2; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

int comb(int a, int b, int m)
{
    return a < b ? 0 : fact[a] * inv[b] % m * inv[a - b] % m;
}

int lucas(int a, int b, int m)
{
    return b == 0 ? 1 : comb(a % m, b % m, m) * lucas(a / m, b / m, m) % m;
}

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;

    init(p);
    cout << lucas(n + m, m, p) << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
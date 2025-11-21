#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
const int MOD = 998244353;

int modpow(int a, int e = MOD - 2)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
        {
            r = r * a % MOD;
        }
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void solve()
{
    int N;
    int D;
    cin >> N >> D;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<int> f(N + 1, 1), dp(N + 1, 1);
    for (int i = 1; i <= N; ++i)
    {
        f[i] = f[i - 1] * i % MOD;
    }
    dp[N] = modpow(f[N]);
    for (int i = N; i >= 1; --i)
    {
        dp[i - 1] = dp[i] * i % MOD;
    }

    int res = 1;
    for (int i = 0; i < N; ++i)
    {
        int op = upper_bound(A.begin(), A.end(), A[i] + D) - A.begin() - i;
        if (op <= 0)
        {
            cout << 0 << endl;
            return;
        }
        res = res * op % MOD;
    }

    int i = 0;
    while (i < N)
    {
        int j = i + 1;
        while (j < N && A[j] == A[i])
        {
            ++j;
        }
        res = res * dp[j - i] % MOD;
        i = j;
    }

    cout << res % MOD << endl;
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
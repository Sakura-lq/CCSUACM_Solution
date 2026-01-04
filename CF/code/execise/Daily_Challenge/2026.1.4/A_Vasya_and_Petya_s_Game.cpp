#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

vector<int> is_prime(N + 1, true), primes;
int init = []()
{
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (is_prime[i])
        {
            int q = 1;
            while (q <= n / i)
            {
                q *= i;
                ans.push_back(q);
            }
        }
    }

    cout << ans.size() << endl;
    for (int i : ans)
    {
        cout << i << " ";
    }

    cout << endl;
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
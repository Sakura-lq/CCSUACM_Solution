#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[200005], n;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += t[k];
        k -= lowbit(k);
    }
    return sum;
}

int query(int l, int r)
{
    return getsum(r) - getsum(l - 1);
}

void solve()
{
    int N, q, d = 0;
    cin >> N >> q;

    n = N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        update(i + 1, nums[i]);
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int c;
            cin >> c;
            d = (d + c) % N;
        }
        else
        {
            int l, r;
            cin >> l >> r;

            auto f = [&](int x) -> int
            {
                int k = d + x;
                return k > N ? k - N : k;
            };

            int L = f(l), R = f(r);
            int ans = 0;

            if (L <= R)
            {
                ans = query(L, R);
            }
            else
            {
                ans = query(L, N) + query(1, R);
            }
            cout << ans << endl;
        }
    }
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

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 5005;
int t1[MAXN], t2[MAXN];
int n;

int lowbit(int x) { return x & -x; }

void update(int *t, int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int *t, int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

void solve()
{
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    size_t clear_bytes = (n + 2) * sizeof(int);

    memset(t1, 0, clear_bytes);
    memset(t2, 0, clear_bytes);

    long long ans = 0;

    ans = 0;
    for (int c = 3; c <= n - 1; ++c)
    {
        memset(t2, 0, clear_bytes);

        for (int d = c + 1; d <= n; ++d)
        {
            update(t2, p[d], 1);
        }
        
        memset(t1, 0, clear_bytes);

        update(t1, p[1], 1);

        for (int b = 2; b <= c - 1; ++b)
        {
            int left = getsum(t1, p[c] - 1);
            int right = getsum(t2, p[b] - 1);
            ans += left * right;
            update(t1, p[b], 1);
        }
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 50005;
int t1[50005], t2[50005];
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int *t, int k, int v)
{
    while (k <= MAXN)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int query(int *t, int k)
{
    int res = 0;
    while(k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

void solve()
{
    cin >> n;

    vector<pair<int, int>>date(n);

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        date[i] = {x, y};
    }

    sort(date.begin(), date.end());

    int ans = 0;
    int cnt_tal = 0;
    int sum_tal = 0;
    for(int i = 0; i < n; i++)
    {
        int v = date[i].first;
        int x = date[i].second;

        int cnt_l = query(t1, x);
        int sum_l = query(t2, x);

        int sum_abs = x * cnt_l - sum_l + (sum_tal - sum_l) - x * (cnt_tal - cnt_l);

        ans += v * sum_abs;

        update(t1, x, 1);
        update(t2, x, x);

        cnt_tal++;
        sum_tal += x;
    }

    cout << ans << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (T--)
    {
        solve();
    }
    return 0;
}
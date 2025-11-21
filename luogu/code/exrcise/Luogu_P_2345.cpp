#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXX = 50000 + 5; // 题目里 x 的范围上界

int n;
int t1[MAXX]; // 计数
int t2[MAXX]; // 坐标和

int lowbit(int x)
{
    return x & -x;
}

void update1(int k, int v)
{
    while (k < MAXX)
    {
        t1[k] += v;
        k += lowbit(k);
    }
}
int query1(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t1[k];
        k -= lowbit(k);
    }
    return res;
}

void update2(int k, int v)
{
    while (k < MAXX)
    {
        t2[k] += v;
        k += lowbit(k);
    }
}
int query2(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t2[k];
        k -= lowbit(k);
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<pair<int, int>> a(n); // {v, x}
    for (int i = 0; i < n; i++)
    {
        int v, x;
        cin >> v >> x;
        a[i] = {v, x};
    }

    sort(a.begin(), a.end()); // 按 v 升序

    long long ans = 0;
    long long cnt_total = 0, sum_total = 0;

    for (int i = 0; i < n; i++)
    {
        int v = a[i].first;
        int x = a[i].second;

        int cnt_left = query1(x);
        int sum_left = query2(x);

        long long sum_abs = (long long)x * cnt_left - sum_left + (sum_total - sum_left) - (long long)x * (cnt_total - cnt_left);

        ans += (long long)v * sum_abs;

        update1(x, 1);
        update2(x, x);
        cnt_total++;
        sum_total += x;
    }

    cout << ans << endl;
    return 0;
}

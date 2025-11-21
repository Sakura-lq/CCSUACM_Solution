#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 5e5 + 50;
const int M = 5e5 + 50;
const int mod = 1e9 + 7;
using namespace std;
void solve()
{
    int x0, y0;
    cin >> x0 >> y0;
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    vector<double> dx, dy;
    for (int i = 1; i <= n; i++)
    {
        //(x0 * a[i][0] > 0 && y0 * a[i][1] > 0)表示点(x0, y0)和点a[i]在同一个象限内
        if (!(x0 * a[i][0] > 0 && y0 * a[i][1] > 0))
        {
            // 点a[i]和点(x0, y0)不在y轴的同一侧
            if (x0 * a[i][0] < 0)
            {
                double t = 1.0 * (a[i][1] - y0) / (a[i][0] - x0) * x0 + y0;
                dy.push_back(t);
            }
            // 点a[i]和点(x0, y0)不在x轴的同一侧
            if (y0 * a[i][1] < 0)
            {
                double t = 1.0 * (a[i][0] - x0) / (a[i][1] - y0) * y0 + x0;
                dx.push_back(t);
            }
        }
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    double res = 4e18;
    k = n - k;
    for (int i = k - 1; i < dx.size(); i++)
    {
        res = min(res, dx[i] - dx[i - k + 1]);
    }
    for (int i = k - 1; i < dy.size(); i++)
    {
        res = min(res, dy[i] - dy[i - k + 1]);
    }
    if (res > 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << fixed << setprecision(8) << res << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
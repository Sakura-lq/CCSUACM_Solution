#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int cnt_z = 0, cnt_f = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            cnt_z++;
        }
        else if (a[i] < 0)
        {
            cnt_f++;
        }
    }

    if (cnt_z == m)
    {
        cout << 0 << endl;
    }
    else if (cnt_z > m && cnt_z < n)
    {
        cout << cnt_z - m << endl;
    }
    else if (cnt_z < m && m - cnt_z < cnt_f)
    {
        cout << m - cnt_z << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return;
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

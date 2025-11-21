#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
void solve()
{
    int n, k;
    cin >> n >> k;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v == 0)
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }

    int mid = (k + 1) / 2;

    if (cnt0 >= k)
    {
        cout << 0 << endl;
        return;
    }

    if (cnt1 >= k)
    {
        cout << 0 << endl;
        return;
    }

    if (cnt1 >= (k - mid + 1))
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
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

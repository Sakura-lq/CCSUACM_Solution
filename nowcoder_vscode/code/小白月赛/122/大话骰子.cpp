#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int a[6], b[6];

void solve()
{
    int cnt[7] = {}; 
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < 6; i++)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }

    int x, y;
    cin >> x >> y;

    if (cnt[y] < x)
    {
        cout << "win" << endl;
    }
    else
    {
        cout << "lose" << endl;
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

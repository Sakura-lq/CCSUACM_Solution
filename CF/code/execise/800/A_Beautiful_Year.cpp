#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int y;
    cin >> y;

    while (1)
    {
        vector<int> cnt(10, 0);
        y++;
        int k = y;
        bool flag = true;
        while (k)
        {
            if (cnt[k % 10])
            {
                flag = false;
                break;
            }
            cnt[k % 10]++;
            k /= 10;
        }
        if (flag)
        {
            cout << y << endl;
            return;
        }
    }

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
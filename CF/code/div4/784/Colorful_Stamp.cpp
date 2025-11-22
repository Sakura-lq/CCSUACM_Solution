#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt1 = 0, cnt2 = 0;

    for (char x : s)
    {
        if (x == 'W')
        {
            if ((cnt1 > 0 && cnt2 == 0) || (cnt2 > 0 && cnt1 == 0))
            {
                cout << "NO" << endl;
                return;
            }

            cnt1 = 0, cnt2 = 0;
        }
        else if (x == 'B')
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }

    cout << ((cnt1 > 0 && cnt2 == 0) || (cnt2 > 0 && cnt1 == 0) ? "NO" : "YES") << endl;
    return;
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
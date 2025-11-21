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
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    int resa = 0, resb = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        resa ^= a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        resb ^= b[i];
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != b[i])
        {
            if (i % 2 == 1)
            {
                cnt1++;
                cnt2 = 0;
            }
            else
            {
                cnt2++;
                cnt1 = 0;
            }
        }
    }

    if (resa == resb)
    {
        cout << "Tie" << endl;
    }
    else
    {
        if (cnt1 > cnt2)
        {
            cout << "Ajisai" << endl;
        }
        else if (cnt1 < cnt2)
        {
            cout << "Mai" << endl;
        }
        else
        {
            if (resa > resb)
            {
                cout << "Ajisai" << endl;
            }
            else if (resa < resb)
            {
                cout << "Mai" << endl;
            }
            else
            {
                cout << "Tie" << endl;
            }
        }
    }
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
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
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max1 = a[0];
    int idx1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max1)
        {
            max1 = a[i];
            idx1 = i;
        }
    }

    int max2 = (idx1 == 0) ? a[1] : a[0];
    int idx2 = (idx1 == 0) ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        if (i == idx1)
        {
            continue;
        }
        if (a[i] > max2)
        {
            max2 = a[i];
            idx2 = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == idx1)
        {
            cout << a[i] - max2 << " ";
        }
        else
        {
            cout << a[i] - max1 << " ";
        }
    }
    cout << endl;
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
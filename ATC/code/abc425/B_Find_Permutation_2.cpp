#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    int hash[n + 1] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == -1)
        {
            continue;
        }

        if (hash[a[i]] != 0)
        {
            cout << "No" << endl;
            return;
        }
        hash[a[i]]++;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (hash[j] == 0)
                {
                    hash[j]++;
                    cout << j << ' ';
                    break;
                }
            }
        }
        else
        {
            cout << a[i] << ' ';
        }
    }

    cout << endl;
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
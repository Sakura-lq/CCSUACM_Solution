#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    map<int, vector<int>> p; 
    for (int i = 0; i < n; i++)
    {
        p[b[i]].push_back(i);
    }

    vector<int> a(n);
    int cur = 1;

    for (auto &[k, idx] : p)
    {
        int sz = idx.size();
        if (sz % k != 0)
        {
            cout << -1 << endl;
            return;
        }
        for (int i = 0; i < sz; i += k)
        {
            for (int j = 0; j < k; j++)
            {
                a[idx[i + j]] = cur;
            }
        }
        cur++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

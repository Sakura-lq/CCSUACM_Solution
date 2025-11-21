#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    vector<int> p(m);

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }

    sort(h.begin(), h.end());
    sort(p.begin(), p.end());

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (h[i] <= p[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    cout << (cnt >= k ? "Yes" : "No") << endl;
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
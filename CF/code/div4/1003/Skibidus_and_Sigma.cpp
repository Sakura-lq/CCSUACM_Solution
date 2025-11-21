#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> sum(n);
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        sum[i].second = i;
        sum[i].first = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            sum[i].first += arr[i][j];
        }
    }

    sort(sum.begin(), sum.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first > b.first; });

    int res = 0;
    int pref = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = sum[i].second;
        for (int j = 0; j < m; j++)
        {
            pref += arr[idx][j];
            res += pref;
        }
    }

    cout << res << endl;
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

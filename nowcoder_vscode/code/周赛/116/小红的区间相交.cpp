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
    vector<pair<int, int>> a(n);
    int maxL = LLONG_MIN, minR = LLONG_MAX;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        maxL = max(maxL, a[i].first);
        minR = min(minR, a[i].second);
    }

    if (maxL > minR)
    {
        cout << "No" << endl;
        return;
    }

    sort(a.begin(), a.end(), [](const pair<int, int> &x, const pair<int, int> &y)
         {
            if (x.first != y.first) return x.first < y.first;
            return x.second < y.second; });

    bool flag = true;
    for (int i = 0; i + 1 < n; ++i)
    {
        if (a[i + 1].second < a[i].second)
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes\n" : "No\n");
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
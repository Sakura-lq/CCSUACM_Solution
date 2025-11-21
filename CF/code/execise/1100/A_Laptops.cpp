#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> com(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        com[i] = {a, b};
    }

    sort(com.begin(), com.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (com[i].second > com[i + 1].second)
        {
            cout << "Happy Alex" << endl;
            return;
        }
    }

    cout << "Poor Alex" << endl;
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
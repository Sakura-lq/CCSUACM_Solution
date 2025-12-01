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
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0 || x != a.back())
        {
            a.push_back(x);
        }
    }

    int cnt = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if ((i == 0 || a[i - 1] > a[i]) && (i == a.size() - 1 || a[i] < a[i + 1]))
        {
            cnt++;
        }
    }

    cout << (cnt == 1 ? "YES" : "NO") << endl;
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
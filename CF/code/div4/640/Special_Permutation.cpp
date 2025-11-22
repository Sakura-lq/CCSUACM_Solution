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

    if (n == 2 || n == 3)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> p;
    int j = 0;

    for (int i = 2; i <= n; i += 2)
    {
        p.push_back(i);
        j++;
    }

    for (int i = (n & 1 ? n : n - 1); i >= 1; i -= 2)
    {
        p.push_back(i);
    }

    if (!(n & 1))
    {
        swap(p[j], p[j + 1]);
    }
    else
    {
        swap(p[j], p[j + 2]);
        swap(p[j + 1], p[j + 2]);
    }

    for (int x : p)
    {
        cout << x << " ";
    }

    cout << endl;
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
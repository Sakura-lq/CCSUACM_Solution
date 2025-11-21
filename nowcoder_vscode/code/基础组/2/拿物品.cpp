#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int MAX_N = 2005;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<tuple<int, int, int>> ob;
    for (int i = 0; i < n; i++)
    {
        ob.emplace_back(a[i], b[i], i + 1);
    }

    sort(ob.begin(), ob.end(), [](const auto &x, const auto &y)
         {
        int sum_x = get<0>(x) + get<1>(x);
        int sum_y = get<0>(y) + get<1>(y);
        return sum_x > sum_y; });

    vector<int> ansA;
    vector<int> ansB;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ansA.push_back(get<2>(ob[i]));
        }
        else
        {
            ansB.push_back(get<2>(ob[i]));
        }
    }

    for (int x : ansA)
    {
        cout << x << ' ';
    }
    cout << endl;
    for (int x : ansB)
    {
        cout << x << ' ';
    }
    cout << endl;
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
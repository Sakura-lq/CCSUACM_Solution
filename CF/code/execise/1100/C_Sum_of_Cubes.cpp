#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

unordered_set<int> cubes;

void pre()
{
    for (int i = 1; i * i * i <= 1000000000000; i++)
    {
        cubes.insert(i * i * i);
    }
}
void solve()
{
    int x;
    cin >> x;

    pre();
    for (int i = 1; i * i * i <= x; i++)
    {
        if (cubes.count(x - i * i * i))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
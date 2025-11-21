#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    int b = min(r, m);
    int a = m - b;
    cout << -a << ' ' << b << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
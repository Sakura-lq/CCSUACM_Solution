#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int nim_sum = 0;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        nim_sum ^= (y - 1); // each token = pile of size (column-1)
    }

    cout << (nim_sum != 0 ? "Mimo" : "Yuyu") << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}

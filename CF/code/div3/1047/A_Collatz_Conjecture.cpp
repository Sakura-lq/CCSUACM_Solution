#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, x;
    cin >> k >> x;
    for (int i = 0; i < k; i++)
    {
        if ((x - 1) % 3 == 0 && (x - 1) / 3 % 2 == 1)
        {
            x = (x - 1) / 3;
        }
        else
        {
            x = x * 2;
        }
    }
    cout << x << "\n";
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

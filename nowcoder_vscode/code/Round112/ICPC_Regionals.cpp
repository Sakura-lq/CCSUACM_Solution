#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    int gold = (n + 9) / 10;
    int silver = gold * 2;
    int bronze = gold * 3;

    if (k <= gold)
    {
        cout << "Gold Medal\n";
    }
    else if (k <= gold + silver)
    {
        cout << "Silver Medal\n";
    }
    else if (k <= gold + silver + bronze)
    {
        cout << "Bronze Medal\n";
    }
    else
    {
        cout << "Da Tie\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += h[i];
    }

    int ans = 1;
    int minSum = sum;

    for (int i = k + 1; i <= n; i++)
    {
        sum += h[i] - h[i - k];
        if (sum < minSum)
        {
            minSum = sum;
            ans = i - k + 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

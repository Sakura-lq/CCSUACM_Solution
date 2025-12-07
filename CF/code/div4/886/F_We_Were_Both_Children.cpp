#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    int cnt[n + 1] = {0};

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        if (x <= n)
        {
            cnt[x]++;
        }
    }

    vector<int> mx(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            mx[j] += cnt[i];
        }
    }

    cout << *max_element(mx.begin(), mx.end()) << endl;
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
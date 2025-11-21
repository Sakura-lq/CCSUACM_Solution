#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> qi;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2 != 0)
        {
            qi.push_back(x);
        }
        else
        {
            sum += x;
        }
    }

    int ans = 0;
    if (qi.empty())
    {
        cout << 0 << endl;
        return;
    }

    sort(qi.begin(), qi.end());

    int f = 0, w = qi.size() - 1;

    ans += sum + qi[w--];

    for (int i = f; i < w; i++, w--)
    {
        ans += qi[w];
    }

    cout << ans << endl;

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
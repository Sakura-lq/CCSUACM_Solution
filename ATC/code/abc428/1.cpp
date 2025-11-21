#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> s1(n1), s2(n2), s3(n3);
    for (int i = 0; i < n1; i++)
    {
        cin >> s1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> s2[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> s3[i];
    }

    int i = 0, j = 0, k = 0;
    int ans = LLONG_MAX;
    while (i < s1.size() && j < s2.size() && k < s3.size())
    {
        int x = s1[i], y = s2[j], z = s3[k];
        int mx = max({x, y, z});
        int mn = min({x, y, z});
        ans = min(ans, 2 * (mx - mn));

        if (mn == x)
        {
            i++;
        }
        else if (mn == y)
        {
            j++;
        }
        else
        {
            k++;
        }
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    auto f = [&](const string &s, char tar) -> int
    {
        vector<int> pos;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == tar)
            {
                pos.push_back(i);
            }
        }

        if (pos.empty() || pos.size() == 1)
        {
            return 0;
        }

        int m = pos.size();
        vector<int> a(m);
        for (int i = 0; i < m; ++i)
        {
            a[i] = pos[i] - i;
        }

        sort(a.begin(), a.end());
        int mid = a[m / 2];
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            ans += abs(a[i] - mid);
        }

        return ans;
    };

    cout << min(f(s, 'a'), f(s, 'b')) << endl;
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

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, L, R;
    cin >> n >> L >> R;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    auto check = [&](int mid) -> bool
    {
        vector<int> g(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            g[i] = pref[i] - mid * i;
        }

        deque<int> dq;
        for (int r = L; r <= n; ++r)
        {
            while (!dq.empty() && g[dq.back()] >= g[r - L])
            {
                dq.pop_back();
            }
            dq.push_back(r - L);

            while (!dq.empty() && dq.front() < r - R)
            {
                dq.pop_front();
            }

            if (!dq.empty())
            {
                if (g[r] - g[dq.front()] >= 0)
                {
                    return true;
                }
            }
        }
        return false;
    };

    int left = 0, right = 1000000000LL;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
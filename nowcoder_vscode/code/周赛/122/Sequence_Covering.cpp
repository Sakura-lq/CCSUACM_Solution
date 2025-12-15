#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> pref(n + 1), pref_max(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], a[i]);
        pref[i] = pref_max[i - 1] == pref_max[i] ? pref[i - 1] : i;
    }

    k = min(k, n - 1);

    int i = 1;
    while (i < n && k > 0)
    {
        if (k >= n - 1)
        {
            while (i <= n)
            {
                a[i] = pref_max[n];
                i++;
            }
            break;
        }

        int mx = pref_max[i + k];

        if (mx > a[i])
        {
            int idx = pref[i + k];

            while (i < idx)
            {
                a[i] = mx;
                i++;
                k--;
            }
        }
        else
        {
            if (pref_max[i + k + 1] > mx)
            {
                mx = pref_max[i + k + 1];
                i++;
                while (k > 0)
                {
                    a[i] = mx;
                    i++;
                    k--;
                }
                break;
            }
            else
            {
                i++;
                if (a[i] < a[i - 1])
                {
                    a[i] = a[i - 1];
                    k--;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }

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
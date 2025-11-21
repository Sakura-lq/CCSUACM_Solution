#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i];
    }

    int ans = 0;

    for (int l = 2; l <= n - 1; l++)
    {
        vector<int> A;
        A.clear();

        for (int r = l; r <= n - 1; r++)
        {
            A.push_back(P[r]);

            int i = 0;
            for (int j = 1; j < l && i < A.size(); j++)
            {
                if (P[j] == A[i])
                {
                    i++;
                }
            }
            for (int j = r + 1; j <= n && i < A.size(); j++)
            {
                if (P[j] == A[i])
                {
                    i++;
                }
            }

            if (i == A.size())
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
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
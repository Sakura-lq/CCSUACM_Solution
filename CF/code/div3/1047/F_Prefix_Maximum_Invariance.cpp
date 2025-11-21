#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        long long ans = 0;

        for (int l = 0; l < n; l++)
        {
            int max_val = 0; // prefix max for current subarray
            for (int r = l; r < n; r++)
            {
                if (r == l)
                    max_val = a[r];
                else
                    max_val = max(max_val, a[r]);

                int f = 0;
                int cur_max = 0;
                // compute f for a[l..r] and b[l..r]
                for (int i = l; i <= r; i++)
                {
                    if (i == l)
                        cur_max = a[i];
                    else
                        cur_max = max(cur_max, a[i]);

                    if (i == l || a[i] > cur_max - a[i])
                    { // forced position
                        if (b[i] == cur_max)
                            f++;
                    }
                    else
                    { // free position
                        if (b[i] <= cur_max)
                            f++;
                    }
                }
                ans += f;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

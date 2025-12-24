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
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt = 1;
            for (int j = 0; j < i; j++)
            {
                for (int k = j + i; k < n; k += i)
                {
                    if (s[k] != s[j])
                    {
                        cnt--;
                    }
                }
            }

            if (cnt >= 0)
            {
                cout << i << endl;
                return;
            }

            cnt = 1;
            for (int j = n - i; j < n; j++)
            {
                for (int k = j - i; k >= 0; k -= i)
                {
                    if (s[k] != s[j])
                    {
                        cnt--;
                    }
                }
            }

            if (cnt >= 0)
            {
                cout << i << endl;
                return;
            }
        }
    }
    
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
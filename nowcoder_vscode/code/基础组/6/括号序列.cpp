#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string s;
    int n;
    cin >> n >> s;

    int res_right = 0, left = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            left++;
        }
        else
        {
            if (left > 0)
            {
                left--;
            }
            else
            {
                res_right++;
            }
        }
    }

    int res_left = 0, right = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        char c = s[i];
        if (c == ')')
        {
            right++;
        }
        else
        {
            if (right > 0)
            {
                right--;
            }
            else
            {
                res_left++;
            }
        }
    }

    cout << res_right + res_left << endl;
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
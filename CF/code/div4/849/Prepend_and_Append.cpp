#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int x = s[i] - '0', y = s[n - i - 1] - '0';
        if(x ^ y)
        {
            res++;
        }
        else
        {
            break;
        }
    }

    cout << n - 2 * res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
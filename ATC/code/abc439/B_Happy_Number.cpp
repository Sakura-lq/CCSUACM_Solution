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
    cin >> n;

    while (n >= 10)
    {
        int temp = n;
        int sum = 0;
        while (temp)
        {
            int yu = temp % 10;
            sum += yu * yu;
            temp /= 10;
        }

        n = sum;
    }

    cout << (n == 1 ? "Yes" : "No") << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
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

    int L = 0, R = 0, U = 0, D = 0;
    for (char c : s)
    {
        if (c == 'L')
        {
            L++;
        }
        else if (c == 'R')
        {
            R++;
        }
        else if (c == 'U')
        {
            U++;
        }
        else
        {
            D++;
        }
    }

    int a = min(L, R), b = min(U, D);
    int dx = abs(L - R), dy = abs(U - D);
    int res = L + R + U + D;
    int ans = 1;

    if (a > 0 && b > 0)
    {
        if (dx == 0 && dy == 0)
        {
            ans = 2 * (a + b); 
        }
        else
        {
            ans += res;
        }
    }
    else if (a == 0 && b == 0)
    {
        ans += res;
    }
    else if (a == 0)
    {
        if (L + R == 0)
        { 
            ans += max(U, D);
        }
        else
        {
            ans += res;
        }
    }
    else
    { 
        if (U + D == 0)
        { 
            ans += max(L, R);
        }
        else
        {
            ans += res;
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
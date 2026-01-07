#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int isprime(int m)
{
    for (int i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
}

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

void solve()
{
    i64 n;
    cin >> n;
    i64 x, y;
    cin >> x >> y;
    i64 a = max(x - 1, y - 1);
    i64 b = max(n - x, n - y);
    if (a <= b)
    {
        cout << "White" << endl;
    }
    else
    {
        cout << "Black" << endl;
    }

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
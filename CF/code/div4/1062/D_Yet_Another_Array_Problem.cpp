#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool siv(int x, const vector<int> &a)
{
    for (int num : a)
    {
        if (gcd(num, x) == 1)
        {
            return true;
        }
    }
    return false;
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int num : a)
    {
        if (num == 1)
        {
            cout << 2 << endl;
            return;
        }
    }

    vector<int> so = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int p : so)
    {
        if (siv(p, a))
        {
            cout << p << endl;
            return;
        }
    }

    for (int x = 37; x <= 1e18; x++)
    {
        if (isPrime(x) && siv(x, a))
        {
            cout << x << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

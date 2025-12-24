#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

vector<int> pre;

int init = []()
{
    for (int i = 2; i < 100005; i++)
    {
        int temp = i;
        bool flag = true;
        while (temp)
        {
            if (temp % 10 > 1)
            {
                flag = false;
                break;
            }
            temp /= 10;
        }

        if (flag)
        {
            pre.push_back(i);
        }
    }

    return 0;
}();

void solve()
{
    int n;
    cin >> n;

    auto f = [](auto &&f, int x) -> bool
    {
        if (x == 1)
        {
            return true;
        }

        bool flag = false;

        for (int i : pre)
        {
            if (x % i == 0)
            {
                flag |= f(f, x / i);
            }
        }

        return flag;
    };

    cout << (f(f, n) ? "YES" : "NO") << endl;
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
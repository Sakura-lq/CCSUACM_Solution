#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int f(int x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve()
{
    int X, Y;
    cin >> X >> Y;

    int app = X;
    int ap = Y;

    for (int i = 3; i <= 10; i++)
    {
        int sum = ap + app;
        int current = f(sum);

        app = ap;
        ap = current;
    }

    cout << ap << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

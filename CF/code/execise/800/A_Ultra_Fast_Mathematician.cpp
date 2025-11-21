#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        if(a[i] == b[i])
        {
            a[i] = '0';
        }
        else
        {
            a[i] = '1';
        }
    }

    cout << a << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
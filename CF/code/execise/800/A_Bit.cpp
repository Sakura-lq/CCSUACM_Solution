#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int x = 0;
    while(n--)
    {
        string s;
        cin >> s;
        if(s.find("++") != string::npos)
        {
            x++;
        }
        if (s.find("--") != string::npos)
        {
            x--;
        }
    }

    cout << x << endl;
    return ;
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
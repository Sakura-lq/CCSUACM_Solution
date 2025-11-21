#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, t;
    cin >> n >> t;
    cin.ignore();
    string s;
    cin >> s;

    while(t--)
    {
        for (int i = 1; i < n; i++)
        {
            if(s[i] == 'G' && s[i - 1] == 'B')
            {
                swap(s[i], s[i - 1]);
                i++;
            }
        }
    }

    cout << s << endl;
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
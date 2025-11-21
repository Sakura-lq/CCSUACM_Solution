#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int cnt = 1;

    cin.ignore();
    string s;
    int flag;
    for (int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            cin >> s;
            flag = s[1] - '0';
            continue;
        }
        cin >> s;

        int a = s[0] - '0';
        if(flag ^= a == 0)
        {
            cnt++;
        }
        flag = s[1] - '0';
    }
    cout << cnt << endl;
    
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
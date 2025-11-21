#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<char>s(n);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    char k = s[0];
    for (int i = 1; i < n; i++)
    {
        if(k == s[i])
        {
            cnt++;
        }
        else
        {
            k = s[i];
        }
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
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int cnt[27] = {};
    for(char ch : b)
    {
        cnt[ch - 'a']++;
    }

    for(char ch : a)
    {
        cnt[ch - 'a']--;
        if(cnt[ch - 'a']  < 0)
        {
            cout << "NO" << endl;
            return;
        } 
    }

    cout << "YES" << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
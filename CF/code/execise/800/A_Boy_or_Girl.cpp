#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    unordered_map<char,int>hash;
    string s;
    cin >> s;

    int cnt = 0;
    for(char ch : s)
    {
        if(hash.find(ch) == hash.end())
        {
            hash[ch]++;
            cnt++;
        }
    }

    cout << (cnt % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << endl;
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
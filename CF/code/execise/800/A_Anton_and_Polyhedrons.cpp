#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    unordered_map<string, int> hash;
    hash["Tetrahedron"] = 4;
    hash["Cube"] = 6;
    hash["Octahedron"] = 8;
    hash["Dodecahedron"] = 12;
    hash["Icosahedron"] = 20;

    cin.ignore();
    string s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cnt += hash[s];
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
    while (T--)
    {
        solve();
    }
    return 0;
}
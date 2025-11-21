#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hash[a[i]]++;
    }

    int diff = hash.size();
    int mx = 0;
    for (auto &[k, v] : hash)
    {
        mx = max(mx, v);
    }

    cout << (diff == mx ? diff - 1 : min(diff, mx)) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

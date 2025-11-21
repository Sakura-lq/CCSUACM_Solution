#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    // q 是 p 的逆序
    for (int i = 0; i < n; i++)
        q[i] = p[n - i - 1];

    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << "\n";
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

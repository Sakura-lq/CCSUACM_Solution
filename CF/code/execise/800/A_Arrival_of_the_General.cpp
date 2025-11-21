#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int mx = *max_element(h.begin(), h.end());
    int mm = *min_element(h.begin(), h.end());

    int max_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] == mx)
        {
            max_pos = i;
            break;
        }
    }

    int min_pos = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (h[i] == mm)
        {
            min_pos = i;
            break;
        }
    }

    int cnt = max_pos + (n - 1 - min_pos);
    if (max_pos > min_pos)
    {
        cnt--;
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
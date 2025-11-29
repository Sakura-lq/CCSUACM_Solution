#include <bits/stdc++.h>
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

    int cnt[10] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x % 10]++;
    }

    vector<int> a;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < min(3LL, cnt[i]); j++)
        {
            a.push_back(i);
        }
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                if ((a[i] + a[j] + a[k]) % 10 == 3)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
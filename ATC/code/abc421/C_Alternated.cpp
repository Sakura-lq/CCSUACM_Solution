#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    vector<int> a;
    for (int i = 0; i < 2 * N; ++i)
    {
        if (S[i] == 'A')
        {
            a.push_back(i);
        }
    }

    int cost1 = 0;
    for (int i = 0; i < N; ++i)
    {
        cost1 += abs(a[i] - 2 * i);
    }

    int cost2 = 0;
    for (int i = 0; i < N; ++i)
    {
        cost2 += abs(a[i] - (2 * i + 1));
    }

    cout << min(cost1, cost2) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

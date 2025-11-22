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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = n - 1;
    int prea = 0, preb = 0;
    int resa = 0, resb = 0;
    int cnt = 0;

    bool flag = true;

    while (i <= j)
    {
        int res = 0;
        cnt++;

        if (flag)
        {
            while (i <= j && res <= preb)
            {
                res += a[i];
                i++;
            }
            resa += res;
            prea = res;
        }
        else
        {
            while (i <= j && res <= prea)
            {
                res += a[j];
                j--;
            }
            resb += res;
            preb = res;
        }

        flag = !flag;
    }

    cout << cnt << " " << resa << " " << resb << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

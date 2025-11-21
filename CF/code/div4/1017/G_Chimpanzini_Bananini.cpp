#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int q;
    cin >> q;

    int sum = 0, re_sum = 0;
    deque<int> dq, re_dq;
    int n = 0;
    int tot = 0;

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
            sum += (tot - last);
            sum -= last * n;
            sum += last;

            last = re_dq.front();
            re_dq.pop_front();
            re_dq.push_back(last);
            re_sum -= (tot - last);
            re_sum += last * n;
            re_sum -= last;
        }
        else if (op == 2)
        {
            swap(sum, re_sum);
            swap(dq, re_dq);
        }
        else
        {
            int k;
            cin >> k;
            n++;
            dq.push_back(k);
            re_dq.push_front(k);
            sum += k * n;
            re_sum += tot;
            re_sum += k;
            tot += k;
        }

        cout << sum << endl;
    }
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
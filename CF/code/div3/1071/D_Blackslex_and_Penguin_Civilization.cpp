#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    i64 mask = (1 << n) - 1;
    vector<i64> nums;
    set<i64> st;
    nums.push_back(mask);
    st.insert(mask);

    int cnt = 0;
    while (mask)
    {
        int j = n;
        for (; j >= 0; j--)
        {
            if (mask & (1 << j))
            {
                mask ^= (1 << j);
                nums.push_back(mask);
                st.insert(mask);
                cnt++;
                break;
            }
        }

        i64 temp = mask;
        for (int k = 0; k < cnt - 1; k++)
        {
            for (int i = n - 1; i > j; i--)
            {
                if (!(temp & (1 << i)))
                {
                    temp |= (1 << i);
                    nums.push_back(temp);
                    st.insert(temp);
                }
            }
        }
    }

    for (int x : nums)
    {
        cout << x << ' ';
    }

    for (int i = 0; i < (1 << n) - 1; i++)
    {
        if (!st.count(i))
        {
            cout << i << ' ';
        }
    }
    cout << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
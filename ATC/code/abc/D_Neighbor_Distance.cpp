#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    set<int> st;
    map<int, int> hash;
    st.insert(0);
    hash[0] = 0;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int x = nums[i];
        st.insert(x);

        auto it = st.find(x);
        int L = -1, R = -1;
        if (it != st.begin())
        {
            auto itL = prev(it);
            L = *itL;
        }
        auto itR = next(it);
        if (itR != st.end())
        {
            R = *itR;
        }

        vector<int> copy;
        if (L != -1)
        {
            copy.push_back(L);
        }
        copy.push_back(x);
        if (R != -1)
        {
            copy.push_back(R);
        }

        for (auto p : copy)
        {
            sum -= hash[p];
        }

        for (auto p : copy)
        {
            int left = -1, right = -1;
            auto itp = st.find(p);
            if (itp != st.begin())
            {
                left = *prev(itp);
            }
            auto itr = next(itp);
            if (itr != st.end())
            {
                right = *itr;
            }

            int val = LLONG_MAX;
            if (left != -1)
            {
                val = min(val, p - left);
            }
            if (right != -1)
            {
                val = min(val, right - p);
            }
            hash[p] = val;
        }

        for (auto p : copy)
        {
            sum += hash[p];
        }

        cout << sum << "\n";
    }
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
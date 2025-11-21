#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> threes;
    vector<int> evens;
    vector<int> odds;

    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0)
            threes.push_back(i);
        else if (i % 2 == 0)
            evens.push_back(i);
        else
            odds.push_back(i);
    }

    vector<int> res;
    int odd_idx = 0;

    for (size_t i = 0; i < evens.size(); i += 2)
    {
        res.push_back(evens[i]);
        if (i + 1 < evens.size())
            res.push_back(evens[i + 1]);
        if (odd_idx < odds.size())
            res.push_back(odds[odd_idx++]);
    }

    for (size_t i = 0; i < threes.size(); i += 2)
    {
        res.push_back(threes[i]);
        if (i + 1 < threes.size())
            res.push_back(threes[i + 1]);
        if (odd_idx < odds.size())
            res.push_back(odds[odd_idx++]);
    }

    while (odd_idx < odds.size())
    {
        res.push_back(odds[odd_idx++]);
    }

    for (int x : res)
        cout << x << " ";
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
}
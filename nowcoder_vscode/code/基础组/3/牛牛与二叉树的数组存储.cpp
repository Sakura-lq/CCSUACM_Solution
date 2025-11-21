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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int size = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            size++;
        }
    }

    cout << "The size of the tree is " << size << endl;
    cout << "Node " << a[1] << " is the root node of the tree" << endl;

    vector<int> father(size + 1, -1), leftc(size + 1, -1), rightc(size + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            continue;
        }
        int node = a[i];

        if (i > 1 && a[i / 2] != -1)
        {
            father[node] = a[i / 2];
        }

        if (2 * i <= n && a[2 * i] != -1)
        {
            leftc[node] = a[2 * i];
        }

        if (2 * i + 1 <= n && a[2 * i + 1] != -1)
        {
            rightc[node] = a[2 * i + 1];
        }
    }

    for (int i = 1; i <= size; i++)
    {
        cout << "The father of node " << i << " is " << father[i]
             << ", the left child is " << leftc[i]
             << ", and the right child is " << rightc[i] << endl;
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
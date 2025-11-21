#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

struct Node
{
    int val;
    Node *prev, *next;
    int sum;
    Node(int v) : val(v), prev(nullptr), next(nullptr), sum(v) {}
};

void solve()
{
    int Q;
    cin >> Q;

    Node *head = new Node(0);
    unordered_map<int, Node *> hash;
    hash[0] = head;

    for (int i = 1; i <= Q; ++i)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x;
            cin >> x;
            Node *xn = hash[x];

            Node *nn = new Node(i);
            nn->sum = xn->sum + i;

            nn->prev = xn;
            nn->next = xn->next;
            if (xn->next)
            {
                xn->next->prev = nn;
                Node *c = xn->next;
                while (c)
                {
                    c->sum += i;
                    c = c->next;
                }
            }
            xn->next = nn;

            hash[i] = nn;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            Node *xn = hash[x];
            Node *yn = hash[y];

            Node *mn = (xn->sum <= yn->sum) ? xn : yn;
            Node *mx = (mn == xn) ? yn : xn;

            int rs = mx->sum - mn->sum - mx->val;
            cout << rs << endl;

            Node *mnx = mn->next;
            mn->next = mx;
            mx->prev = mn;

            int adj = rs;
            Node *c = mx;
            while (c)
            {
                c->sum -= adj;
                c = c->next;
            }

            Node *dc = mnx;
            while (dc && dc != mx)
            {
                Node *t = dc;
                dc = dc->next;
                hash.erase(t->val);
                delete t;
            }
        }
    }

    Node *c = head;
    while (c)
    {
        Node *t = c;
        c = c->next;
        delete t;
    }

    return;
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

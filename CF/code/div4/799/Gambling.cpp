#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

struct Node
{
    long long pref, suf, val, sum;
    Node() : pref(LLONG_MIN / 4), suf(LLONG_MIN / 4), val(LLONG_MIN / 4), sum(0) {}
    Node(long long x) : pref(x), suf(x), val(x), sum(x) {}
};

Node mergeNode(const Node &a, const Node &b)
{
    Node c;
    c.sum = a.sum + b.sum;
    c.pref = max(a.pref, a.sum + b.pref);
    c.suf = max(b.suf, b.sum + a.suf);
    c.val = max({a.val, b.val, a.suf + b.pref});
    return c;
}

struct SegTree
{
    int n;
    vector<Node> t;
    long long neutral; // leaf value when "not selected" (-1)
    SegTree(int _n = 0, long long assign_value = -1)
    {
        init(_n, assign_value);
    }
    void init(int _n, long long assign_value)
    {
        n = _n;
        neutral = assign_value;
        t.assign(4 * max(1LL, n), Node());
        if (n > 0)
            build(1, 0, n - 1);
    }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            t[p] = Node(neutral);
            return;
        }
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
        t[p] = mergeNode(t[p << 1], t[p << 1 | 1]);
    }
    void modify(int p, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            t[p] = Node(val);
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m)
            modify(p << 1, l, m, pos, val);
        else
            modify(p << 1 | 1, m + 1, r, pos, val);
        t[p] = mergeNode(t[p << 1], t[p << 1 | 1]);
    }
    void modify(int pos, long long val)
    {
        modify(1, 0, n - 1, pos, val);
    }
    Node query(int p, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return t[p];
        int m = (l + r) >> 1;
        if (qr <= m)
            return query(p << 1, l, m, ql, qr);
        if (ql > m)
            return query(p << 1 | 1, m + 1, r, ql, qr);
        return mergeNode(query(p << 1, l, m, ql, qr), query(p << 1 | 1, m + 1, r, ql, qr));
    }
    Node query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        unordered_map<long long, vector<int>> pos;
        pos.reserve(n * 2);
        for (int i = 0; i < n; ++i)
            pos[a[i]].push_back(i);

        SegTree st(n, -1);
        long long bestVal = LLONG_MIN;
        long long bestA = -1;

        for (auto &kv : pos)
        {
            long long val = kv.first;
            auto &vec = kv.second;
            for (int idx : vec)
                st.modify(idx, 1);
            Node res = st.query(0, n - 1);
            if (res.val > bestVal)
            {
                bestVal = res.val;
                bestA = val;
            }
            for (int idx : vec)
                st.modify(idx, -1);
        }

        int bestL = 0, bestR = 0;
        long long cur = 0;
        long long mx = LLONG_MIN;
        int curL = 0;
        for (int i = 0; i < n; ++i)
        {
            int v = (a[i] == bestA ? 1 : -1);
            cur += v;
            if (cur > mx)
            {
                mx = cur;
                bestL = curL;
                bestR = i;
            }
            if (cur <= 0)
            {
                cur = 0;
                curL = i + 1;
            }
        }

        cout << bestA << " " << (bestL + 1) << " " << (bestR + 1) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

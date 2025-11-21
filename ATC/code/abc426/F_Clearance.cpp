#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


const int MAXN = 10000000;

struct Node
{
    int sum;
    int mx;
    int mm;
    int lazy;
    int left, right;
} tree[MAXN];

int cnt;
int root;
int n, q;

inline int create(int val)
{
    int idx = cnt++;
    tree[idx].sum = val;
    tree[idx].mx = val;
    tree[idx].mm = val;
    tree[idx].lazy = 0;
    tree[idx].left = -1;
    tree[idx].right = -1;
    return idx;
}

inline void push_down(int p, int l, int r)
{
    if (tree[p].lazy == 0)
    {
        return;
    }
    int mid = (l + r) >> 1;
    int val = tree[p].lazy;

    if (tree[p].left == -1)
    {
        tree[p].left = create(0);
    }
    int left = tree[p].left;

    int left_size = mid - l + 1;
    tree[left].sum -= val * left_size;
    tree[left].mx -= val;
    tree[left].mm -= val;
    tree[left].lazy += val;

    if (tree[p].right == -1)
    {
        tree[p].right = create(0);
    }
    int right = tree[p].right;

    int right_size = r - mid;
    tree[right].sum -= val * right_size;
    tree[right].mx -= val;
    tree[right].mm -= val;
    tree[right].lazy += val;

    tree[p].lazy = 0;
}

inline void push_up(int p)
{
    int left = tree[p].left;
    int right = tree[p].right;

    tree[p].sum = 0;
    tree[p].mx = 0;
    tree[p].mm = 0x3f3f3f3f3f3f3f3f;

    if (left != -1)
    {
        tree[p].sum += tree[left].sum;
        tree[p].mx = max(tree[p].mx, tree[left].mx);
        tree[p].mm = min(tree[p].mm, tree[left].mm);
    }
    if (right != -1)
    {
        tree[p].sum += tree[right].sum;
        tree[p].mx = max(tree[p].mx, tree[right].mx);
        tree[p].mm = min(tree[p].mm, tree[right].mm);
    }
    if (left == -1 && right == -1)
    {
        tree[p].mm = tree[p].mx;
    }
}

void build(int &p, int l, int r, int a[])
{
    if (p == -1)
    {
        p = create(0);
    }
    if (l == r)
    {
        tree[p].sum = a[l];
        tree[p].mx = a[l];
        tree[p].mm = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tree[p].left, l, mid, a);
    build(tree[p].right, mid + 1, r, a);
    push_up(p);
}

int query(int p, int l, int r, int ql, int qr, int k)
{
    if (p == -1)
    {
        return 0;
    }
    if (qr < l || ql > r)
    {
        return 0;
    }
    if (tree[p].mx == 0)
    {
        return 0;
    }

    if (ql <= l && r <= qr)
    {
        if (tree[p].mx <= k)
        {
            int res = tree[p].sum;
            tree[p].sum = 0;
            tree[p].mx = 0;
            tree[p].mm = 0;
            tree[p].lazy = 0;
            return res;
        }
        if (tree[p].mm > k)
        {
            int cnt = r - l + 1;
            int res = k * cnt;
            tree[p].sum -= res;
            tree[p].mx -= k;
            tree[p].mm -= k;
            tree[p].lazy += k;
            return res;
        }
    }

    if (l == r)
    {
        int take = min(tree[p].sum, k);
        tree[p].sum -= take;
        tree[p].mx = tree[p].sum;
        tree[p].mm = tree[p].sum;
        return take;
    }

    push_down(p, l, r);
    int mid = (l + r) >> 1;

    int left_res = query(tree[p].left, l, mid, ql, qr, k);
    int right_res = query(tree[p].right, mid + 1, r, ql, qr, k);

    push_up(p);

    return left_res + right_res;
}

inline void read(int &x)
{
    x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

inline void print(int x)
{
    if (x == 0)
    {
        putchar('0');
        putchar('\n');
        return;
    }
    char buf[20];
    int len = 0;
    while (x > 0)
    {
        buf[len++] = x % 10 + '0';
        x /= 10;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(buf[i]);
    }
    putchar('\n');
}

void solve()
{
    cnt = 0;
    root = -1;

    read(n);
    int *a = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }

    build(root, 1, n, a);
    delete[] a;

    read(q);
    while (q--)
    {
        int l, r, k;
        read(l);
        read(r);
        read(k);
        print(query(root, 1, n, l, r, k));
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
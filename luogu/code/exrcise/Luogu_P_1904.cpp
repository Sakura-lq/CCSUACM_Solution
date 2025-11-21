#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int l, r;
    int lazy;
    int h;
} t[40005];

struct b
{
    int l, r;
    int h;
} b[10005];

int a[10005];

void build(int id, int l, int r)
{
    t[id].l = l;
    t[id].r = r;
    t[id].lazy = 0;
    if (t[id].l == t[id].r)
    {
        t[id].h = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void Push(int id)
{
    if (t[id].lazy)
    {
        t[id * 2].lazy = max(t[id * 2].lazy, t[id].lazy);
        t[id * 2 + 1].lazy = max(t[id * 2 + 1].lazy, t[id].lazy);
        t[id * 2].h = max(t[id * 2].h, t[id * 2].lazy);
        t[id * 2 + 1].h = max(t[id * 2 + 1].h, t[id * 2 + 1].lazy);
        t[id].lazy = 0;
    }
}

void update(int id, int l, int r, int c)
{
    if (t[id].l == l && t[id].r == r)
    {
        t[id].h = max(t[id].h, c);
        t[id].lazy = max(t[id].lazy, c);
        return;
    }
    Push(id);
    if (r <= t[id * 2].r)
    {
        update(id * 2, l, r, c);
    }
    else if (l >= t[id * 2 + 1].l)
    {
        update(id * 2 + 1, l, r, c);
    }
    else
    {
        update(id * 2, l, t[id * 2].r, c);
        update(id * 2 + 1, t[id * 2 + 1].l, r, c);
    }
    
    t[id].h = max(t[id * 2].h, t[id * 2 + 1].h);
}

int query(int id, int l, int r)
{
    if (t[id].l == l && t[id].r == r)
    {
        return t[id].h;
    }
    Push(id);
    if (r <= t[id * 2].r)
    {
        return query(id * 2, l, r);
    }
    else if (l >= t[id * 2 + 1].l)
    {
        return query(id * 2 + 1, l, r);
    }
    else
    {
        return max(query(id * 2, l, t[id * 2].r), query(id * 2 + 1, t[id * 2 + 1].l, r));
    }
}

int main()
{
    build(1, 1, 10000);
    int l, h, r;
    int cnt = 1;
    while (cin >> b[cnt].l >> b[cnt].h >> b[cnt].r)
    {
        cnt++;
    }

    for (int i = 1; i < cnt; ++i)
    {
        update(1, b[i].l, b[i].r - 1, b[i].h);
    }
    for (int i = 1; i <= 10000; ++i)
    {
        a[i] = query(1, i, i);
    }
    for (int i = 1; i <= 10000; ++i)
    {
        if (a[i] != a[i - 1])
        {
           cout << i << ' ' << a[i] << ' ';
        }
    }
    return 0;
}

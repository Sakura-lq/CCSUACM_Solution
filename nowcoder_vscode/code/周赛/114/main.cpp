#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N = 2e5 + 50;
struct Info {
    int lmin, lmax, rmin, rmax;
    int lazy, v;
};
Info operator+(const Info &a, const Info &b) {
	Info c = {0, 0, 0, 0, 0, 0};
    c.lmin = min(a.lmin, b.lmin);
    c.rmin = min(a.rmin, b.rmin);
    c.lmax = max(a.lmax, b.lmax);
    c.rmax = max(a.rmax, b.rmax);
    return c;
}
int w[N];
struct SegmentTree {
	struct node {
		int l, r;
        int sizmin, sizmax;
        Info info;
	} tr[N << 2];
	
	void change(int p, int lazy, int v){
        tr[p].info.lazy = lazy;
		tr[p].info.v = v;
        if(lazy == 1){
            tr[p].info.lmin = tr[p].info.lmax = v;
            tr[p].info.rmin = v + tr[p].sizmin;
            tr[p].info.rmax = v + tr[p].sizmax;
        }else if(lazy == 2){
            tr[p].info.rmin = tr[p].info.rmax = v;
            tr[p].info.lmax = v - tr[p].sizmin;
            tr[p].info.lmin = v - tr[p].sizmax;
        }
    }
	void pushup(int p) {
		tr[p].info = tr[p << 1].info + tr[p << 1 | 1].info;
	}
	void pushdown(int p) {
		if(tr[p].info.lazy){
			change(p << 1, tr[p].info.lazy, tr[p].info.v);
			change(p << 1| 1, tr[p].info.lazy, tr[p].info.v);
			tr[p].info.lazy = 0;
		}
	}
	void build(int p, int l, int r) {
		tr[p] = {l, r};
		if(l == r) {
            tr[p].sizmin = tr[p].sizmax = w[l];
            tr[p].info = {0, 0, w[l], w[l], 0, 0};
			return ;
		}
		int m = (l + r) >> 1;
		build(p << 1, l, m);
		build(p << 1 | 1, m + 1, r);
        tr[p].sizmin = min(tr[p << 1].sizmin, tr[p << 1 | 1].sizmin);
        tr[p].sizmax = max(tr[p << 1].sizmax, tr[p << 1 | 1].sizmax);
		pushup(p);
	}

	void update(int p, int x, int y, int op, int v) {
		if(x <= tr[p].l && tr[p].r <= y) {
			change(p, op, v);
			return ;
		}
		int m = (tr[p].l + tr[p].r) >> 1;
		pushdown(p);
		if(x <= m) {
			update(p << 1, x, y, op, v);
		}
		if(y > m) {
			update(p << 1 | 1, x, y, op, v);
		}
		pushup(p);
	}
	Info query(int p, int x) {
		if(tr[p].l == tr[p].r) {
			return tr[p].info;
		}
		int m = (tr[p].l + tr[p].r) >> 1;
		pushdown(p);
		if(x <= m) {
			return query(p << 1, x);
		}else{
			return query(p << 1 | 1, x);
		}
	}
	int Query(int p, int x) {
		if(tr[p].info.lmin > x){
			return tr[p].r - tr[p].l + 1;
		}
        if(tr[p].info.rmax <= x){
            return tr[p].r - tr[p].l + 1;
        }
        if(tr[p].info.lmax <= x && tr[p].info.rmin > x){
            return 0;
        }
		// if(tr[p].l == tr[p].r){
		// 	return 0;
		// }
		pushdown(p);
		return Query(p << 1, x) + Query(p << 1 | 1, x);
	}
};
SegmentTree S;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    S.build(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int op, x;
        cin >> op >> x;
        if(op == 1){
			Info c = S.query(1, x);
			S.update(1, 1, x, 1, c.lmin);
        }else if(op == 2){
			Info c = S.query(1, x);
			S.update(1, 1, x, 2, c.rmin);
		}else{
			cout << n - S.Query(1, x) << endl;
		}
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
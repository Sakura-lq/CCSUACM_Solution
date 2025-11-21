#include<bits/stdc++.h>
using namespace std;
using i64=long long;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<int> ans(2 * n + 1);
    for (int x = 2; x <= 2 * n; x++) {
        vector<int> cnt(n);
        int ma = 0, tk = 0;
        for (int i = 1; i < x; i++) {
            if (i > n || x - i > n) {
                continue;
            }
            int p1 = p[i], p2 = p[x - i];
            int k;
            if (p1 >= p2) {
                k = p1 - p2;
            }
            else {
                k = n - (p2 - p1);
            }
            cnt[k]++;
            if (cnt[k] > ma || (cnt[k] == ma && k < tk)) {
                ma = cnt[k];
                tk = k;
            }
        }
        ans[x] = tk;
    }

    while (q--) {
        int x;
        cin >> x;
        if (x < 2 || x > 2 * n) {
            cout << 0 << '\n';
        }
        else {
            cout << ans[x] << '\n';
        }
    }
}

int main(){
    solve();
}
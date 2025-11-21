#include <bits/stdc++.h>

using i64 = long long;

void solve(void) {
    int n; std::cin >> n;
    if(n < 4) {
        std::cout << n << '\n';
        for(int i = 1; i <= n; i++) std::cout << i << ' ';
        return;
    }
    std::vector<int> num, Q;
    num.push_back(n);
    while(num.back() >= 4) {
        auto x = num.back();
        int q = x / 5;
        int r = x % 5;
        num.push_back(q + ((r != 4) ? r : 0));
        Q.push_back(q);
    }
    std::cout << num.back() << '\n';
    if(num.back() == 0) return;
    std::vector<int> ans;
    for(int i = 1; i <= num.back(); i++) {
        int idx = i;
        for(int j = (int)num.size() - 1; j >= 0; j--) {
            if(idx <= Q[j]) idx *= 5;
            else idx = 5 * Q[j] + (idx - Q[j]);
        }
        ans.push_back(idx);
    }
    for(auto i : ans) std::cout << i << ' ';
}

int main(void) {
    int t = 1;
    //std::cin >> t;
    while(t--) solve();
    return 0;
}
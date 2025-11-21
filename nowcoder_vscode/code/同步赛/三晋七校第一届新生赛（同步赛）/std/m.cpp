#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        ans = ans * (r - l + 1);
    }
    if (ans <= 1e5) {
        std::cout << "NO TLE\n";
    } else if (ans > 1e7) {
        std::cout << "TLE\n";
    } else {
        std::cout << "POSSIBLE\n";
    }
    return 0;
}
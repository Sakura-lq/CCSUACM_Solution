void solve() {
    int n;
    std::cin >> n;

    int x0, y0;
    std::cin >> x0 >> y0;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;

        if (x > x0) {
            cnt++;
        } else if (x == x0) {
            if (y0 > y) {
                cnt++;
            }
        }
    }

    int g, s, c;
    g = n / 10 * 1;
    s = n / 10 * 3;
    c = n / 10 * 6;

    if (cnt <= g) {
        std::cout << "gold" << "\n"; 
    } else if (cnt <= s) {
        std::cout << "silver" << "\n";
    } else if (cnt <= c) {
        std::cout << "bronze" << "\n";
    } else {
        std::cout << "iron" << "\n";
    }
}
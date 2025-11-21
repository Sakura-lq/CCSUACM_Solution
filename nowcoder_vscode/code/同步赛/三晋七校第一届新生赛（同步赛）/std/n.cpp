void solve() {
    std::string s;
    std:cin >> s;

    for (int i = 0; i < s.size(); i++) {
        std::cout << '9' - s[i];
    }
    std::cout << "\n";
}
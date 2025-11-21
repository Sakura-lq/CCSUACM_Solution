void Given_By_YMWL() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int l = 0, r = 0, ans = -1;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' && flag == 0) {
			flag = 1;
			l = i;
			continue;
		}
		if (s[i] == '(' && flag == 1) {
			l = i;
		}
		if (s[i] == ')' && flag == 1) {
			r = i;
			flag = 0;
			ans = std::max(ans, r - l + 1);
		}
	}
	std::cout << ans << "\n";
}
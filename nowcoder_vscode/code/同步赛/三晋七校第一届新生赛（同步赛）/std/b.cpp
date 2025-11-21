void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    long long ans = 0;
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    ans += std::min(1LL * A[0] * a, b * 1LL);
    for (int i = 0; i < n - 1; i++) {
        ans += std::min(1LL * (A[i + 1] - A[i]) * a, b * 1LL);
    }
    std::cout << ans << "\n";
}
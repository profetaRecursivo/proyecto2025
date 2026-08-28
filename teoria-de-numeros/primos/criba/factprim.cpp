vector<int> prime_factors(int n) {
    vector<int> facts;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            facts.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) facts.push_back(n);
    return facts;
}
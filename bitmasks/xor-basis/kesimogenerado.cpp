// ksimo mas pequeno
vector<ull> basis;
void insertBasis(ull x) {
	for (ull b : basis) x = min(x, x ^ b);
	if (!x) return;
	for (ull &b : basis) b = min(b, b ^ x);
	basis.push_back(x);
	sort(basis.begin(), basis.end());
}
int main() {  // con la base actual  cual es el ksimo mas grande?
	int x;
	cin >> x;
	ull k = x;
	if (k > (1ULL << sz(basis))) {
		cout << "-1\n";return 0;
		// continue;
	}
    //para grande k = 2^basis - k + 1
	k--;  // convertir a 0-index
	ull res = 0;
	for (int i = 0; i < sz(basis); i++) {
		if (k & (1ULL << i)) res ^= basis[i];
	}
	cout << res << "\n";
}
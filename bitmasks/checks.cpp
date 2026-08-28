bool esdivpor2alak(int n, int k) {
	int pot = 1 << k;
	return (n & (pot - 1)) == 0;
}
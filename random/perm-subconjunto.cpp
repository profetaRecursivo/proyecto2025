vector<int> perm(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rng);
    return p;
}
vector<int> subc(vector<int>& arr, int k){
    vector<int> ans;
    sample(arr.begin(), arr.end(), back_inserter(ans), k, rng);
    return ans;
}
struct Node {
    int total_sum, max_sum, min_sum, prefix_sum, suffix_sum;
    Node() : total_sum(0), max_sum(INT_MIN), min_sum(INT_MAX), prefix_sum(0), suffix_sum(0) {}
};
Node combine(const Node &left, const Node &right) {
    Node res;
    res.total_sum = left.total_sum + right.total_sum;
    res.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
    res.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
    res.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
    res.min_sum = min({left.min_sum, right.min_sum, left.suffix_sum + right.prefix_sum});
    return res;
}
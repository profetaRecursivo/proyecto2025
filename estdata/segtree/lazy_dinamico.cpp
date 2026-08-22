#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXNODES = 4000000; // q * log(maxVal)

struct Node {
    ll val;
    Node() : val(0) {}
    Node(ll v) : val(v) {}
};

Node op(Node a, Node b) {
    return Node(a.val + b.val);
}

Node merge(Node a, Node b) {
    return op(a, b);
}

Node tr[MAXNODES];
ll lazy_[MAXNODES];
bool hasLazy[MAXNODES];
int lc[MAXNODES], rc[MAXNODES];
int cnt = 1;

int newNode() {
    cnt++;
    lc[cnt] = 0;
    rc[cnt] = 0;
    tr[cnt] = Node();
    hasLazy[cnt] = false;
    return cnt;
}

void ensureChildren(int node) {
    if (!lc[node]) lc[node] = newNode();
    if (!rc[node]) rc[node] = newNode();
}

void push_ass(int node, ll b, ll e) {
    if (!hasLazy[node]) return;

    if (b == e) {
        hasLazy[node] = false;
        return;
    }

    ensureChildren(node);
    for (int hijo : {lc[node], rc[node]}) {
        tr[hijo] = Node(lazy_[node]);
        lazy_[hijo] = lazy_[node];
        hasLazy[hijo] = true;
    }

    hasLazy[node] = false;
}

void update(int node, ll b, ll e, ll i, ll j, ll val) {
    if (i <= b && e <= j) {
        tr[node] = Node(val);
        lazy_[node] = val;
        hasLazy[node] = true;
        return;
    }

    push_ass(node, b, e); // ya crea los hijos internamente si hace falta

    ll mid = b + (e - b) / 2;
    if (j <= mid) update(lc[node], b, mid, i, j, val);
    else if (i > mid) update(rc[node], mid+1, e, i, j, val);
    else {
        update(lc[node], b, mid, i, j, val);
        update(rc[node], mid+1, e, i, j, val);
    }

    tr[node] = merge(tr[lc[node]], tr[rc[node]]);
}

Node query(int node, ll b, ll e, ll i, ll j) {
    if (i <= b && e <= j) return tr[node];

    push_ass(node, b, e);

    ll mid = b + (e - b) / 2;
    if (j <= mid) return query(lc[node], b, mid, i, j);
    if (i > mid) return query(rc[node], mid+1, e, i, j);
    return merge(query(lc[node], b, mid, i, j), query(rc[node], mid+1, e, i, j));
}

int main() {
    ll LO = 0, HI = 1000000000000000000LL;
    int root = 1;
    tr[root] = Node();
    hasLazy[root] = false;
    lc[root] = rc[root] = 0;

    // ejemplo:
    // update(root, LO, HI, i, j, val);
    // query(root, LO, HI, i, j).val;

    return 0;
}
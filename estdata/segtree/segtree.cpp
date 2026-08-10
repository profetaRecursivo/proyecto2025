const int tam = 100010;
struct Node{};
Node merge(Node a, Node b){
    return Node(op(a, b));
}
int arr[tam];
Node tr[4*tam];
void build(int b, int e, int node){
    if(b == e){
        tr[node] = Node(arr[b]);
        return;
    }
    int l = node*2, r = l+1, mid = (b+e)/2;
    build(b, mid, l);build(mid+1, e, r);
    tr[node] = max(tr[l], tr[r]);
}
void update(int b, int e, int node, int pos, int value){
    if(b == e){
        tr[node] = Node(value);
        return;
    }
    int mid = (b+e)/2, l = node*2, r = l+1;
    if(pos <= mid)update(b, mid, l, pos, value);
    else update(mid+1, e, r, pos, value);
    tr[node] = max(tr[l], tr[r]);
}
Node query(int b, int e, int node, int i, int j){
    if(j<i)return 0;
    if(i<= b and e<= j)return tr[node];
    int mid = (b+e)/2, l = node*2, r = l+1;
    if(j <= mid)return query(b, mid, l, i, j);
    if(i>mid)return query(mid+1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid+1, e, r, i, j));
}

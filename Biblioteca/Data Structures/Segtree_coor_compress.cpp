struct Node{
    ll v;

    Node(ll v=0L): v(v){}

    Node operator+ (const Node &o){
        //merge function
        return Node(v + o.v);
    }
};

struct Segtree{
    vector<Node> tree;
    ll sz;

    Segtree(ll n): sz(n){
        this->tree.resize(4*n);
    }

    void update(ll n, ll l, ll r, ll p, Node &node){
        if(l == r){
            //update the node
            tree[n] = tree[n] + node;
            return;
        }

        ll m = (l+r)/2;
        if(p <= m) update(2*n, l, m, p, node);
        else update(2*n + 1, m+1, r, p, node);

        tree[n] = tree[2*n] + tree[2*n+1];
    }

    void update(ll p, Node &node){
        update(1, 1, sz, p, node);
    }

    Node querie(ll n, ll l, ll r, ll a, ll b){
        if(a <= l && r <= b) return tree[n];

        if(r < a || l > b){
            //return node that doesnt change the segtree
            return NULL;
        }

        ll m = (l+r)/2;
        Node left = querie(2*n, l, m, a, b);
        Node right = querie(2*n + 1, m+1, r, a, b);

        return left+right;
    }

    Node querie(ll l, ll r){
        return querie(1, 1, sz, l, r);
    }
};

template <class T>
struct Compress{
    vector<T> vec;

    void push(const T &t) vec.push_back(t);

    int build(){
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec.size();
    }

    int operator[] (const T &t){
        auto it = lower_bound(vec.begin(), vec.end(), t);
        return (it-vec.begin());
    }
}
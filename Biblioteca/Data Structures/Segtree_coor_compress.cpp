struct Node{
    ll v;

    // Buildar um fator neutro para o no (no caso de segtreeeh zero)
    Node(ll v=0L): v(v){}

    Node operator+ (const Node &o){
        //merge function
        return Node(v + o.v);
    }
};

struct Segtree{
    vector<Node> tree;
    ll sz;

    Segtree(ll n, vll &vec = {}): sz(n){
        this->tree.resize(4*n);

        if(vec.size() == n) build(vec);
    }

    void build(vll &vec, ll n = 1, ll l = 1, ll r = sz){
        if(l == r){
            tree[n] = Node(vec[l]);
            return;
        }

        ll m = (l+r)/2;
        build(vec, 2*n, l, m);
        build(vec, 2*n + 1, m+1, r);

        tree[n] = tree[2*n] + tree[2*n + 1];
    }

    void update(ll n, ll l, ll r, ll p, ll val){
        if(l == r){
            //update the node
            tree[n] = tree[n] + Node(val);
            return;
        }

        ll m = (l+r)/2;
        if(p <= m) update(2*n, l, m, p, val);
        else update(2*n + 1, m+1, r, p, val);

        tree[n] = tree[2*n] + tree[2*n+1];
    }

    void update(ll p, ll val){
        update(1, 1, sz, p, val);
    }

    Node query(ll n, ll l, ll r, ll a, ll b){
        if(a <= l && r <= b) return tree[n];

        if(r < a || l > b){
            //return node that doesnt change the segtree
            return Node();
        }

        ll m = (l+r)/2;
        Node left = query(2*n, l, m, a, b);
        Node right = query(2*n + 1, m+1, r, a, b);

        return left+right;
    }

    Node query(ll l, ll r){
        return query(1, 1, sz, l, r);
    }
};

template <class T>
struct Compress{
    vector<T> vec;

    void push(const T &t){
        vec.push_back(t);
    }

    int build(){
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec.size();
    }

    int operator[] (const T &t){
        auto it = lower_bound(vec.begin(), vec.end(), t);
        return (it-vec.begin());
    }
};
struct Node{
    ll v;

    // Buildar um fator neutro para o node (no caso de segtree de soma eh zero)
    Node(){ v = 0;}

    Node(ll v): v(v){}

    //FUNCAO DE MERGE
    Node operator+ (const Node &o){
        //merge function
        Node result;
        result.v = v + o.v;
        return result;
    }

    ll getValue(){
        return v;
    }
};

struct Segtree{
    vector<Node> tree;
    ll sz;

    Segtree(vector<Node> &vec){
        sz = vec.size();

        this->tree.resize(4*sz);
        build(vec, 1, 1, sz);
    }

    void build(vector<Node> &vec, ll n, ll l, ll r){
        if(l == r){
            tree[n] = vec[l];
            return;
        }

        ll m = (l+r)/2;
        build(vec, 2*n, l, m);
        build(vec, 2*n + 1, m+1, r);

        tree[n] = tree[2*n] + tree[2*n + 1];
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

    void update(ll p, Node node){
        update(1, 1, sz, p, node);
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
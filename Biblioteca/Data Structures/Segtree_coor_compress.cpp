struct Node{
    ll v;

    // Buildar um fator neutro para o node (no caso de segtree de soma eh zero)
    Node(ll _v = 0){
      v = _v;
    }

    Node(ll _v): v(_v){}

    //FUNCAO DE MERGE
    Node operator+ (const Node &o){
        //merge function
        Node result(v + o.v);
        return result;
    }

    ll getValue(){  return v; }
};

//Caso de exemplo é segtree de soma
struct Segtree{
    vector<Node> tree;
    ll sz;

    Segtree(vector<ll> &vec){
        sz = vec.size();

        tree.resize(4*sz);
        build(1, 0, sz, vec);
    }

    private:
        void build(ll n, ll l, ll r, vector<ll> &vec){
            if(r-l == 1){
                tree[n] = Node(vec[l]);
                return;
            }

            ll m = (l+r)/2;
            build(2*n, l, m, vec);
            build(2*n + 1, m, r, vec);

            tree[n] = tree[2*n] + tree[2*n + 1];
        }

        void update(ll n, ll l, ll r, ll p, ll val){
            if(r-l == 1){
                //update the node
                tree[n] = tree[n] + Node(val);
                return;
            }

            ll m = (l+r)/2;
            if(p < m) update(2*n, l, m, p, node);
            else update(2*n + 1, m+1, m, p, node);

            tree[n] = tree[2*n] + tree[2*n+1];
        }

        Node query(ll n, ll l, ll r, ll a, ll b){
            // Range outside query returns node that doesn't affect asnwer
            if(b <= l || r <= a) return Node();
            if(a <= l && r <= b) return tree[n];

            ll m = (l+r)/2;
            Node left = query(2*n, l, m, a, b);
            Node right = query(2*n + 1, m, r, a, b);

            return left+right;
        }

    public:
        void update(ll p, ll val){
            update(1, 0, sz, p, val);
        }

        Node query(ll l, ll r){
            return query(1, 0, sz, l, r);
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
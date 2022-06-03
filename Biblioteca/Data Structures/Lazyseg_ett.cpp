struct Node{
    ll val;

    Node(ll _val = 0){
        val = _val;
    }

    Node operator+ (const Node &o){
        ll sum = val + o.val;
        return Node(sum);
    }
};

//Caso de exemplo é segtree de soma
struct Segtree{
    vector<Node> tree;
    vector<ll> lazy;
    ll sz;

    Segtree(vector<Node> &vec){
        sz = vec.size();

        tree.resize(4*sz);
        lazy.resize(4*sz);
        build(1, 0, sz, vec);
    }

    private:
        void build(ll n, ll l, ll r, vector<Node> &vec){
            if(r-l == 1){
                tree[n] = vec[l];
                return;
            }

            ll m = (l+r)/2;
            build(2*n, l, m, vec);
            build(2*n + 1, m, r, vec);

            tree[n] = tree[2*n] + tree[2*n + 1];
        }

        void apply(ll n, ll l, ll r){
            tree[n].val += (r-l)*lazy[n];

            if(r-l > 1){
                lazy[2*n] += lazy[n];
                lazy[2*n + 1] += lazy[n];
            }

            lazy[n] = 0;
        }

        void update(ll n, ll l, ll r, ll a, ll b, ll val){
            apply(n, l, r);

            if(b <= l || r <= a) return;
            if(a <= l && r <= b){
                lazy[n] += val;
                return;
            }

            ll m = (l+r)/2;

            update(2*n, l, m, a, b, val);
            update(2*n + 1, m, r, a, b, val);

            apply(2*n, l, m);
            apply(2*n + 1, m, r);

            tree[n] = tree[2*n] + tree[2*n + 1];
        }

        Node query(ll n, ll l, ll r, ll a, ll b){
            apply(n, l, r);

            if(b <= l || r <= a) return Node();
            if(a <= l && r <= b) return tree[n];

            ll m = (l+r)/2;
            Node left = query(2*n, l, m, a, b);
            Node right = query(2*n + 1, m, r, a, b);

            return left+right;
        }

    public:
        //Update from [l, r)
        void update(ll l, ll r, ll val){
            update(1, 0, sz, l, r, val);
        }

        //Update from [p, p+1)
        void update(ll p, ll val){
            update(1, 0, sz, p, p+1, val);
        }

        //Make query from [l, r)
        Node query(ll l, ll r){
            return query(1, 0, sz, l, r);
        }

        //Make query from [p, p+1)
        Node query(ll p){
            return query(1, 0, sz, p, p+1);
        }
};

ll t = 0;
vector<ll> tin, tout, rin;
void setEtt(vector<ll> &adj, ll node = 0){
    rin[t] = node;
    tin[node] = t++;

    for(auto next: adj[node]) setEtt(adj, next);

    tout[node] = t;
}
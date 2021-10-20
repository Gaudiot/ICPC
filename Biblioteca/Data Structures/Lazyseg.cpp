struct Node{
    ll v;

    // Buildar um fator neutro para o node (no caso de segtree de soma eh zero)
    Node(){ v = 0;}

    Node(ll _v): v(_v){}

    //FUNCAO DE MERGE
    Node operator+ (const Node &o){
        //merge function
        Node result;
        result.v = v + o.v;
        return result;
    }

    Node operator* (const ll &val){
        //Lazy update function
        Node result;
        result.v = v * val;
        return result;
    }

    ll getValue(){  return v; }

    bool empty(){
        //Check if node has an empty value
        return v == 0;
    }

    void clear(){
        //Set node to empty
        v = 0;
    }
};

struct Lazyseg{
    vector<Node> tree;
    vector<Node> lazy;
    ll sz;

    Lazyseg(vector<Node> vec){
        sz = vec.size()-1; //-1 is a correction factor
        tree.resize(4*sz);
        lazy.resize(4*sz);

        build(vec, 1, 1, sz);
    }

    private:
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

        void push(ll n, ll l, ll r){
            //Doesnt propagate if it is a leaf
            if(l < r){
                lazy[2*n] = lazy[2*n] + lazy[n];
                lazy[2*n + 1] = lazy[2*n + 1] + lazy[n];
            }

            lazy[n].clear();
        }

        void apply(ll n, ll l, ll r){
            if(!lazy[n].empty()){
                ll m = (l+r)/2;
                tree[2*n]  = tree[2*n] + (lazy[n] * (m - l + 1));
                tree[2*n + 1] = tree[2*n + 1] + (lazy[n] * (r - m));

                push(n, l, r);
            }

            lazy[n].clear();
        }

        void update(ll n, ll l, ll r, ll a, ll b, Node &node){
            if(r < a || b < l) return;

            ll m = (l+r)/2;
            if(a <= l && r <= b){
                lazy[n] = lazy[n] + node;
                tree[n] = tree[n] + (node * (r - l + 1));
                return;
            }

            apply(n, l, r);
            update(2*n, l, m, a, b, node);
            update(2*n + 1, m+1, r, a, b, node);

            tree[n] = tree[2*n] + tree[2*n + 1];
        }

        Node query(ll n, ll l, ll r, ll a, ll b){
            if(r < a || b < l){
                //return node that doesnt change the segtree
                return Node();
            }

            apply(n, l, r);
            if(a <= l && r <= b){
                return tree[n];
            }

            ll m = (l+r)/2;
            Node left = query(2*n, l, m, a, b);
            Node right = query(2*n + 1, m+1, r, a, b);

            return left+right;
        }

    public:
        void update(ll l, ll r, ll val){
            Node node(val);
            update(1, 1, sz, l, r, node);
        }

        Node query(ll l, ll r){
            return query(1, 1, sz, l, r);
        }
};
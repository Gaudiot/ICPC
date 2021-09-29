struct Dsu{
    vll ds;
    vll sz;

    Dsu(ll n){
        ds.resize(n);
        sz.resize(n);

        build(n);
    }

    void build(ll n){
        for(int i = 0 ; i < n ; i++){
            ds[i] = i;
            sz[i] = 1;
        }
    }

    ll find(ll i){
        if(ds[i] != i) ds[i] = find(ds[i]);
        return ds[i];
    }

    void merge(ll u, ll v){
        u = find(u); v = find(v);
        if(sz[u] < sz[v]) swap(u, v);
        if(u != v) sz[u] += sz[v];
        ds[v] = u;
    }

    ll getSize(ll i){
        i = find(i);
        return sz[i];
    }
};
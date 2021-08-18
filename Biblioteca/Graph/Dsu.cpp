vll ds(n);
vll sz(n);

void dsBuild(){
    for(int i = 0 ; i < n ; i++){
        ds[i] = i;
        sz[i] = 1;
    }
}

ll dsFind(ll i){
    if(ds[i] != i) ds[i] = dsFind(ds[i]);
    return ds[i];
}

void dsUnion(ll a, ll b){
    a = dsFind(a); b = dsFind(b);
    if(sz[a] < sz[b]) swap(a, b);
    if(a != b) sz[a] += sz[b];
    ds[b] = a;
}
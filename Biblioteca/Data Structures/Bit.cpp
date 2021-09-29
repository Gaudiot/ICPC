struct Bit{
    vll vec;
    ll sz;

    Bit(ll sz){
        this->sz = sz+5;
        vec.resize(sz+5);
    }

    void update(ll p, ll val = 1){
        while(p < sz){
            vec[p] += val;
            p += (p & -p);
        }
    }

    ll query(ll p){
        ll ans = 0;
        while(p > 0){
            ans += vec[p];
            p -= (p & -p);
        }

        return ans;
    }
};
struct Rabin{
    ll base, mod;
    vll pot, has;

    //alt-base = 787
    //alt-mod = 1e9+87
    Rabin(string &str, ll base = 997 , ll mod = 1e9+7): mod(mod), base(base){
        ll sz = str.size();
        pot.resize(sz+1);
        has.resize(sz+1);

        build(str);
    }

    void build(string &str){
        pot[0] = 1;
        has[0] = str[0];
        for(int i = 1 ; i < str.size() ; i++){
            pot[i] = (pot[i-1]*base)%mod;
            has[i] = ((has[i-1]*base) + str[i])%mod;
        }
    }

    ll getkey(ll l, ll r){
        ll ans = has[r];
        if(l > 0) ans = ((ans - pot[r-l+1]*has[l-1])%mod + mod)%mod;
        return ans;
    }
};
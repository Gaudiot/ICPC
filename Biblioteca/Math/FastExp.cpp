//Maybe it is not necessary to take the mod
const ll mod = 1e18;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;

        a = (a*a)%mod;
        b >>= 1;
    }

    return ans;
}
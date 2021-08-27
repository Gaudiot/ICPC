//Calculate n choose k C(n, k)

ll comb(ll n, ll k){
    if(n-k < k) k = n-k;
    ll ans = 1;
    for(int i = 1 ; i <= k ; i++){
        ans = (ans*(n-i+1))/i;
    }
    return ans;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

const ll maxn;
const ll mod;
vll fat(maxn+5);

void build(){
    fat[0] = 1;
    for(int i = 1 ; i <= maxn ; i++){
        fat[i] = (i*fat[i-1])%mod;
    }
}

//It can be optimized if instead of invmod(fat[k]*fat[n-k]) we precalculate
//all the invmod from [1, maxn] (this can de done in O(maxn))
//and use invmod[k] % mod * invmod[n-k] % mod
ll comb(ll n, ll k){
    return fat[n] * invmod(fat[k] * fat[n-k] % mod) % mod;
}
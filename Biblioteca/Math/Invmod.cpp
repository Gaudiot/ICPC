/*
Modular multiplicative inverse is the value x that makes  a*x ≡ 1 (mod m)
It only exists if gcd(a,m) = 1
*/

//Calculates a single multiplicative inverse

const ll mod;

ll invmod(ll a){
    ll ans = fexp(a, phi(mod)-1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//Calculates all multiplicative inverse in range [1, n)
//For this to work n MUST be prime

vector<ll> inv(n);
inv[1] = 1;
for(int i = 2 ; i < n ; i++){
    inv[i] = mod - ((mod/i)*inv[mod%i])%mod;
}
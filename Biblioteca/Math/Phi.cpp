//Calculate PHI for a singular n

ll phi(ll n){
    ll ans = n;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0){
            ans -= ans/i;
            while(n%i == 0) n /= i;
        }
    }

    if(n > 1) ans -= ans/n;
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Calculates PHI for a range [1, n]

vll phi(n+5);

void sieve(ll n){
    for(int i = 1 ; i <= n ; i++) phi[i] = i;
    for(int i = 2 ; i <= n ; i++){
        if(phi[i] == i){
            for(int j = i ; j <= n ; j += i){
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
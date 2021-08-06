//Ternary search using integer
ll func(ll x){
    return x*x; //inser custom unimodal function here
}

ll ternary(ll l, ll r){
    ll m1, m2;

    while(r-l >= 3){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;

        if(func(m1) < func(m2)) l = m1; //If looking for minimum value on range, invert "<" to ">"
        else r = m2;
    }

    ll ans = func(l);
    for(int i = l+1 ; i <= r ; i++){
        ans = max(ans, func(i)); //If looking for minimum value on range, use "min" instead of "max"
    }

    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Ternary search using double
const double eps = 1e-8;

double func(double x){
    return x*x; //insert custom unimodal function here
}

double ternary(double l, double r){
    double m1, m2;

    while(r-l > eps){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;

        if(func(m1) < func(m2)) l = m1; //If looking for minimum value on range, invert "<" to ">"
        else r = m2;
    }

    return func(l);
}
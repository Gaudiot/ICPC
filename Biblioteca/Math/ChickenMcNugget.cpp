//Given x and y coprimes, find the largest n that cannnot be written as m*x+n*y

ll nugget(ll a, ll b){
    ll mdc = __gcd(a, b);
    a /= mdc;
    b /= mdc;

    return (a*b - a - b);
}
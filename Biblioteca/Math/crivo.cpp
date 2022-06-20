vector<ll> primes;
vector<bool> sieve;

void crivo(ll lim){
  primes.push_back(2);
  sieve.resize(lim+5, true);
  for(int i = 3 ; i < lim ; i++){
    if(!sieve[i]) continue;

    primes.push_back(i);
    if(i > lim/i) continue;

    for(int j = i*i ; j < lim ; j += i+i) sieve[j] = false;
  }
}
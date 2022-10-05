void getDigits(ll a){
    digits.clear();
    while(a){
        digits.push_back(a%10);
        a /= 10;
    }
    reverse(digits.begin(), digits.end());
}

//Counts how many numbers have exactly K digits D in its decimal representation
int K, D;
int solve(int pos, int qtt, bool smaller){
    if(qtt > K) return 0;
    if(pos == digits.size()) return q(qtt == K);
    if(smaller && dp[pos][qtt] != -1) return dp[pos][qtt];

    int ans = 0;
    int lim = smaller ? 9 : digits[pos];

    for(int d = 0 ; d <= lim ; d++){
        bool nsmaller = smaller || (d < lim);
        int nqtt = qtt + (d == D);
        ans += solve(pos+1, nqtt, nsmaller);
    }

    if(smaller) dp[pos][qtt] = ans;
    return ans;
}
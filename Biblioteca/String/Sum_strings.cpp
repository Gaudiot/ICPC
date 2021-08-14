//Por enquanto só funciona soma de dois números positivos
string sum_strings(string &a, string &b){
    string ans;
    ll len = max(a.size(), b.size())+1;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ans.resize(len, '0');
    a.resize(len, '0');
    b.resize(len, '0');

    for(int i = 0 ; i < len-1 ; i++){
        int d = a[i] + b[i] + ans[i] - 3*'0';

        ans[i] = d%10 + '0';
        ans[i+1] = d/10 + '0';
    }

    if(ans[len-1] == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
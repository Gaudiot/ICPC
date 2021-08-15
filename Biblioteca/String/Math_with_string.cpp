void pre(string &a, string &b, string &ans){
    ll len = max(a.size(), b.size()) + 1;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ans.resize(len, '0');
    a.resize(len, '0');
    b.resize(len, '0');
}

void pos(string &ans){
    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
}

//Por enquanto so funciona subtracao se a>b>=0
string sub_strings(string a, string b){
    string ans;
    
    pre(a, b, ans);

    for(int i = 0 ; i < ans.size()-1 ; i++){
        a[i] -= '0'; b[i] -= '0'; ans[i] -= '0';
        if(a[i] >= b[i]+ans[i]){
            ans[i] = (a[i]-b[i]-ans[i]);
        }else{
            ans[i] += (10+a[i]) - (b[i]+ans[i]);
            b[i+1]++;
        }
        
        a[i] += '0'; b[i] += '0'; ans[i] += '0';
    }

    pos(ans);
    
    return ans;
}

//Por enquanto so funciona soma de dois números positivos
string sum_strings(string a, string b){
    string ans;
    
    pre(a, b, ans);

    for(int i = 0 ; i < ans.size()-1 ; i++){
        int d = a[i] + b[i] + ans[i] - 3*'0';

        ans[i] = d%10 + '0';
        ans[i+1] = d/10 + '0';
    }

    pos(ans);
    
    return ans;
}
struct ZArr{
  vector<ll> z;
  bool hasPattern = false;
  ll patternSize = 0;

  ZArr(string str, string pattern = ""){
    if(!pattern.empty()){
        str = pattern + "$" + str;
        hasPattern = true;
        patternSize = pattern.size();
    }
    
    build(str);
  }
  
  private:
    void build(string &str){
      ll sz = str.size();
      z.resize(sz);

      ll l = 0, r = 0;
      for(ll i = 1 ; i < sz ; i++){
        if(r-i >  z[i-l]){
          z[i] = z[i-l];
        }else{
          l = i;
          r = max(r, i);
          while(r < sz && str[r] == str[r-l]) r++;
          z[i] = r-l;
        }
      }
    }
    
  public:
    pair<ll, ll> findLongest(){ //returns {index, size};
      pair<ll, ll> p = {-1, 0};
      ll sz = 0;

      for(int i = 0 ; i < z.size() ; i++){
        if(sz < z[i]){
          sz = z[i];
          p = {i, sz};
        }
      }

      return p;
    }

    vector<ll> findPattern(){
      vector<ll> ans;
      if(!hasPattern) return ans;

      for(int i = 0 ; i < z.size() ; i++){
        if(z[i] == patternSize) ans.push_back(i - (patternSize + 1));
      }

      return ans;
    }
};
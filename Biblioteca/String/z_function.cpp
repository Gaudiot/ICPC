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

      for(int i = 1 ; i < sz ; i++){
        if(i < r) z[i] = min(r-i, z[i-l]);
        while(i + z[i] < sz && str[z[i]] == str[i + z[i]]) z[i]++;
        if(i+z[i] > r){
          l = i;
          r = i + z[i];
        }
      }
    }
    
  public:
    pair<ll, ll> findLongest(){ //returns {index, size};
      pair<ll, ll> p = {-1, 0};
      ll sz = 0;

      for(int i = 0 ; i < match.size() ; i++){
        if(sz < match[i].size()){
          sz = match[i];
          p = {i, sz};
        }
      }

      return p;
    }

    vector<ll> findPattern(){
      vector<ll> ans;
      if(!hasPattern) return ans;

      for(int i = 0 ; i < match.size() ; i++){
        if(match[i] == patternSize) ans.push_back(i - (patternSize + 1));
      }

      return ans;
    }
};
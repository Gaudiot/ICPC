struct KMP{
    private:
        string str;
        vll border;

    KMP(string &str): str(str){
        border.resize(str.size());

        int j = 0;
        for(int i = 1 ; i < str.size() ; i++){
            while(j > 0 && str[j] != str[i]){
                j = border[j];
            }

            if(str[i] == str[j]) j++;
            border[i] = j;
        }
    }

    bool matchWith(string &txt){
        ll freq = 0;
        int j = 0;
        for(int i = 0 ; i < txt.size() ; i++){
            while(j > 0 && str[i] != str[j]){
                j = border[j-1];
            }
            if(str[i] == str[j]) j++;
            if(j == str.size()){
                freq++;
                j = border[j];
            }
        }
        return freq;
    }
};
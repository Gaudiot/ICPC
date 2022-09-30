const int ms;

struct Matrix{
    vector<bitset<ms>> vec;
    ll n, m;

    Matrix(ll _n, ll _m){
        n = _n;
        m = _m;

        vec.resize(n);
    }

    void set(ll r, ll c, int v = 1){
        vec[r][c] = v;
    }

    int gauss(){
        int p = 0;
        for(int k = 0 ; k < m ; k++){
            int pivot = p;
            for(int i = p ; i < n ; i++){
                if(vec[i][k] == 1){
                    swap(vec[i], vec[p]);
                    break;
                }
            }

            if(vec[p][k] == 0) continue;
            for(int i = 0 ; i < n ; i++){
                if(i != p && vec[i][k] == 1) vec[i] ^= vec[p];
            }
            p++;
        }

        if(!valid()) return -1;
        return (m - p);
    }

    bool valid(){
        for(int i = 0 ; i < n ; i++){
            if(vec[i].count() == 1 && vec[i][ms-1] == 1) return false;
        }

        return true;
    }
};
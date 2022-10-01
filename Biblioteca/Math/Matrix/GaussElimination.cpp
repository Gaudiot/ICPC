const ld eps = 1e-7;

struct Matrix{
    vector<vector<ld>> mat;
    ll n, m;

    Matrix(ll _n, ll _m){
        n = _n;
        m = _m;

        mat.resize(n, vector<ld>(m+1));
    }

    void set(ll r, ll c, ld v = 1){
        mat[r][c] = v;
    }

    int gauss(){
        ll p = 0;
        vector<ll> where(m, -1);
        for(int k = 0 ; k < m ; k++){
            ll pivot = p;
            //look for pivot
            for(int i = p ; i < n ; i++){
                if(abs(mat[i][k]) > abs(mat[pivot][k])){
                    pivot = i;
                }
            }
            //pivot has null value
            if(abs(mat[pivot][k]) < eps) continue;
            for(int i = 0 ; i < m ; i++) swap(mat[pivot][i], mat[p][i]);
            where[k] = p;

            ld g = mat[p][k];
            for(int i = 0 ; i < m ; i++) mat[p][i] /= g;

            for(int i = 0 ; i < n ; i++){
                if(i != p){
                    ld c = mat[i][k]/mat[p][k];
                    for(int j = 0 ; j < m ; j++) mat[i][j] -= c*mat[p][j];
                }
            }
            p++;
        }

        vector<ll> ans(m);
        for(int i = 0 ; i < n ; i++){
            if(where[i] != -1) ans[i] = mat[where[i]][m]/mat[where[i]][i];
        }
        for(int i = 0 ; i < n ; i++){
            ld sum = 0;
            for(int j = 0 ; j < m ; j++) sum += ans[j]*mat[i][j];
            if(abs(sum - mat[i][m]) > eps) return 0;
        }
        for(int i = 0 ; i < n ; i++){
            if(where[i] == -1) return 2;
        }
        return 1;
    }
};
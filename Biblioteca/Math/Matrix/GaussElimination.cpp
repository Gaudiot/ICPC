const ld eps = 1e-7;

struct Matrix{
    vector<vector<ld>> mat;
    ll n, m;

    Matrix(ll _n, ll _m){
        n = _n;
        m = _m;

        mat.resize(n, vector<ld>(m));
    }

    void gauss(){
        ll p = 0;
        for(int k = 0 ; k < n ; k++){
            ll pivot = p;
            //look for pivot
            for(int i = p ; i < n ; i++){
                if(abs(mat[i][k]) > abs(mat[pivot][k])){
                    pivot = i;
                }
            }
            //pivot has null value
            if(abs(mat[pivot][k]) < eps) assert(0);
            for(int i = 0 ; i < m ; i++) swap(mat[pivot][i], mat[p][i]);

            ld g = mat[p][k];
            for(int i = 0 ; i < m ; i++){
                mat[p][i] /= g;
            }

            for(int i = 0 ; i < n ; i++){
                if(i != p){
                    ld c = mat[i][k]/mat[p][k];
                    for(int j = 0 ; j < m ; j++) mat[i][j] -= c*mat[p][j];
                }
            }

            p++;
        }
    }
};
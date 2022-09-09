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
        for(int j = 0 ; j < min(n, m) ; j++){
            ll pivot = j;
            //look for pivot
            for(int i = j ; i < n ; i++){
                if(abs(mat[i][j]) > abs(mat[pivot][j])){
                    pivot = i;
                }
            }
            //pivot has null value
            if(abs(mat[pivot][j]) < eps) continue;
            for(int i = 0 ; i < m ; i++) swap(mat[j][i], mat[pivot][i]);

            for(int i = 0 ; i < n ; i++){
                if(i != j){
                    ld c = mat[i][j]/mat[j][j];
                    for(int k = 0 ; k < m ; k++) mat[i][k] -= c*mat[j][k];
                }
            }
        }
    }
};
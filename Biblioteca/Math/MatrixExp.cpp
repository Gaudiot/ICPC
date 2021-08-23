const ll mod;
const ll sz;

struct Matrix{
    vector<vll> mat;

    Matrix(){
        mat.resize(sz, vll(sz, 0));
    }

    Matrix operator* (const Matrix &p){
        Matrix ans;
        for(int i = 0 ; i < sz ; i++){
            for(int j = 0 ; j < sz ; j++){
                for(int k = 0 ; k < sz ; k++){
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k]*p.mat[k][j])%mod;
                }
            }
        }

        return ans;
    }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0 ; i < sz ; i++) ans[i][i] = 1;

    while(b){
        if(b&1) ans = (ans*a);

        a = a*a;
        b >>= 1;
    }
}
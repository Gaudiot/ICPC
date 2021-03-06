const ll logn = 20;

vector<ll> depth(n);
vector<vector<ll>> adj(n);
vector<vector<ll>> up(n, vector<ll>(logn, -1));

void dfs(ll node = 0){ //Starts at root
    for(auto next: adj[node]){
        up[next][0] = node;
        depth[next] = depth[node] + 1;
        dfs(next);
    }
}

void build(){
    dfs();

    for(int j = 1 ; j < logn ; j++){
        for(int i = 0 ; i < n ; i++){
            if(up[i][j-1] == -1) continue;
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

ll getLca(ll a, ll b){
    if(depth[a] < depth[b]) swap(a, b);

    ll k = depth[a] - depth[b];
    for(int i = 0 ; i < logn ; i++){
        if(k & (1<<i)){
            a = up[a][i];
        }
    }

    if(a == b) return a;

    for(int i = logn-1 ; i >= 0 ; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}
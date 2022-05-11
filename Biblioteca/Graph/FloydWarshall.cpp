ll n; //number of nodes

//-1 distance means there is no road connecting the points
vector<vector<ll>> dist(n, vector<ll>(n, -1));

for(int k = 0 ; k < n ; k++){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(dist[i][k] == -1LL || dist[k][j] == -1LL) continue;
            if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
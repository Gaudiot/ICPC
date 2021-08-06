ll n; //number of nodes

vector<vll> dist(n, vll(n, -1));

for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
        for(int k = 0 ; k < n ; k++){
            if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][i]){
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
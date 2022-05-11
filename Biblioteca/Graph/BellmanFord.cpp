typedef pair<ll, ll> pair<ll, ll>;

vector<ll> dist(n, -1); //distance to source array, -1 implies infinite distance
vector<vector<pair<ll, ll>>> adj(n); //matriz de adjacência [<distance, node>]

//Remember it works on graphs with negative edges
//Remember it only works on graphs without negative loops
void bellman(ll source){
    dist[source] = 0;

    for(int k = 1 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            if(dist[i] == -1) continue;

            ll d, next;
            for(auto p: adj[i]){
                d = dist[i] + p.first;
                next = p.second;

                if(dist[next] == -1 || dist[next] > d) dist[next] = d;
            }
        }
    }
}
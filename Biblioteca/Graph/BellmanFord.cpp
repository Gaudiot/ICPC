const ll inf = (1LL<<40);

vector<ll> dist(n, inf); //distance to source
vector<vector<pair<ll, ll>>> adj(n); //matriz de adjacência [<distance, node>]

//Remember it works on graphs with negative edges
//Remember it only works on graphs without negative loops
void bellman(ll source = 0){
    dist[source] = 0;

    bool diff = true;
    for(int k = 1 ; k < n && diff ; k++){
        diff = false;
        for(int i = 0 ; i < n ; i++){
            ll d, next;
            for(auto p: adj[i]){
                d = dist[i] + p.first;
                next = p.second;

                if(dist[next] > d){
                    dist[next] = d;
                    diff = true;
                }
            }
        }
    }
}
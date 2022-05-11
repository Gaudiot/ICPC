typedef pair<ll, ll> pair<ll, ll>;

vector<ll> dist(n, -1); //distance to source array, -1 implies infinite distance
vector<vector<pair<ll, ll>>> adj(n); //matriz de adjacência [<distance, node>]

//Remember it only works on graphs without negative edges
void dijkstra(ll source, ll end = -1LL){
    dist[source] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //<distance, node>
    pq.push({0, source});

    ll d, node;
    while(!pq.empty()){
        d = pq.top().first;
        node = pq.top().second;
        pq.pop();

        if(d > dist[node]) continue;
        if(node == end) break;

        ll nd, next;
        for(auto p: adj[node]){
            nd = p.first + d;
            next = p.second;

            if(dist[next] == -1 || dist[next] > nd){
                dist[next] = nd;
                pq.push({nd, next});
            }
        }
    }
}
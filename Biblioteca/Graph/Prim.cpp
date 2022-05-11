typedef pair<ll, ll> pair<ll, ll>;

ll prim(vector<vector<pair<ll, ll>>> &adj, ll source = 0){
    ll n = adj.size();

    vector<ll> dist(n, -1);
    dist[source] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; //<dist, node>
    pq.push({0, source});

    vector<bool> visit(n, false);

    ll d, node;
    while(!pq.empty()){
        d = pq.top().first;
        node = pq.top().second;
        pq.pop();

        if(visit[node]) continue;
        visit[node] = true;

        ll nd, next;
        for(auto p: adj[node]){
            nd = p.first; next = p.second;

            if(visit[next]) continue;
            if(dist[next] != -1 && nd >= dist[next]) continue;
            dist[next] = nd;

            pq.push({nd, next});
        }
    }

    ll ans = 0;
    for(auto v: dist) ans += v;

    return ans;
}
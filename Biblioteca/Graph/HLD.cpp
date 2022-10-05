void dfs_sz(int v = 0) {
    sz[v] = 1;
    for(auto &u: adj[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[adj[v][0]]) {
            swap(u, adj[v][0]);
        }
    }
}

void dfs_hld(int v = 0) {
    in[v] = t++;
    for(auto u: adj[v]) {
        nxt[u] = (u == adj[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = t;
}
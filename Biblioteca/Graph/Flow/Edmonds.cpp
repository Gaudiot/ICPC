struct Flow{
  vector<vector<ll>> adj;
  vector<vector<ll>> pipes;
  ll sz;
  ll maxFlow = 0;

  Flow(ll _sz = 0){
    sz = _sz + 2;
    adj.resize(sz);
    pipes.resize(sz, vector<ll>(sz));
  }

  void addPipe(ll u, ll v, ll cap){
    pipes[u][v] = cap;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void addSource(ll u, ll cap){
    addPipe(0, u, cap);
  }

  void addSink(ll u, ll cap){
    addPipe(u, sz-1, cap);
  }

  ll bfs(vector<ll> &prev){
    fill(prev.begin(), prev.end(), -1);
    prev[0] = -2;

    queue<pair<ll, ll>> q; //<node, flow>
    q.push({0, inf});

    ll node, flow;
    while(!q.empty()){
      node = q.front().first;
      flow = q.front().second;
      q.pop();

      ll nflow;
      for(auto next: adj[node]){
        if(prev[next] == -1 && pipes[node][next] > 0){
          prev[next] = node;
          nflow = min(flow, pipes[node][next]);
          if(next == sz-1) return nflow;
          q.push({next, nflow});
        }
      }
    }

    return 0;
  }

  ll max(){
    if(maxFlow > 0) return maxFlow;
    vector<ll> prev(sz);

    ll flow;
    while((flow = bfs(prev)) > 0){
      ll node = sz-1;
      while(node > 0){
        ll p = prev[node];
        pipes[p][node] -= flow;
        pipes[node][p] += flow;
        node = p;
      }
      maxFlow += flow;
    }

    return maxFlow;
  }
};
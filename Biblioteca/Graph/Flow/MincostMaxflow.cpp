const ll inf = (1LL<<40);

struct Pipe{
  ll u, v, cap, cost;

  Pipe(ll _u, ll _v, ll _cap = 0, ll _cost = 0){
    u = _u;
    v = _v;
    cap = _cap;
    cost = _cost;
  }
};

struct MCMF{
  vector<Pipe> pipes;
  vector<vector<ll>> adj;
  ll sz;

  vector<ll> dist;
  vector<ll> prev_id;

  MCMF(ll _sz){
    sz = _sz + 2;

    adj.resize(sz);
    dist.resize(sz);
    prev_id.resize(sz);
  }

  private:
    bool bfs(){
      fill(dist.begin(), dist.end(), inf);
      dist[0] = 0;

      vector<bool> mark(sz, false);
      
      queue<ll> q;
      q.push(0);

      while(!q.empty()){
        ll u = q.front();
        q.pop();

        mark[u] = false;

        for(auto next: adj[u]){
          ll v = pipes[next].v;
          ll cost = pipes[next].cost;
          if(pipes[next].cap < 1) continue;
          if(dist[u] <= dist[v] + cost) continue;

          dist[u] = dist[v] + cost;
          prev_id[v] = next;

          if(!mark[v]){
            mark[v] = true;
            q.push(v);
          }
        }
      }

      return dist[sz-1] < inf;
    }

    pair<ll, ll> dfs(){
      ll flow = -1, cost = 0;

      ll cur = sz-1;
      while(cur != 0){
        ll prev = prev_id[cur];
        if(flow == -1 || flow > pipes[prev].cap) flow = pipes[prev].cap;
        cur = pipes[prev].u;
      }

      cur = sz-1;
      while(cur != 0){
        ll prev = prev_id[cur];
        cost += (pipes[prev].cost*flow);

        pipes[prev].cap -= flow;
        pipes[prev^1].cap += flow;

        cur = pipes[prev].u;
      }

      return {cost, flow};
    }

  public:
    void addPipe(ll u, ll v, ll cap, ll cost){
      adj[u].push_back(pipes.size());
      pipes.push_back(Pipe(u, v, cap, cost));
      adj[v].push_back(pipes.size());
      pipes.push_back(Pipe(v, u, 0, -cost));
    }

    void addSource(ll u, ll cap){
      addPipe(0, u, cap, 0);
    }

    void addSink(ll u, ll cap){
      addPipe(u, sz-1, cap, 0);
    }

    pair<ll, ll> calc(ll maxFlow = -1){
      ll mincost = 0, flow = 0;

      while(bfs()){
        pair<ll, ll> p = dfs();
        mincost += p.first;
        flow += p.second;
      }

      return {mincost, flow};
    }
};
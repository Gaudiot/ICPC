const ll inf = (1LL<<40);

struct Pipe{
  ll v, cap;

  Pipe(ll _v, ll _cap){
    v = _v;
    cap = _cap;
  }
};

struct Flow{
  ll sz;
  vector<bool> dry;
  vector<Pipe> pipes;
  vector<vector<ll>> adj;

  vector<ll> lv;

  Flow(ll _sz){
    sz = _sz+2;

    adj.resize(sz);
    lv.resize(sz, -1);
    dry.resize(sz, false);
  }

  private:
    bool bfs(){
      fill(lv.begin(), lv.end(), -1);
      fill(dry.begin(), dry.end(), false);

      queue<ll> q;
      q.push(0);
      lv[0] = 0;

      ll u;
      while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto next: adj[u]){
          ll v = pipes[next].v;
          if(pipes[next].cap < 1) continue;
          if(lv[v] != -1) continue;

          lv[v] = lv[u] + 1;
          q.push(v);
        }
      }

      return lv[sz-1] != -1;
    }

    ll dfs(ll u = 0, ll flow = inf){
      if(dry[u]) return 0;

      if(flow == 0) return 0;
      if(u == sz-1) return flow;

      ll ret = 0;
      for(auto next: adj[u]){
        ll v = pipes[next].v;
        if(lv[u] + 1 != lv[v]) continue;
        ll f = dfs(v, min(flow, pipes[next].cap));

        flow -= f;
        ret += f;
        pipes[next].cap -= f;
        pipes[next^1].cap += f;
      }

      if(ret == 0) dry[u] = true;

      return ret;
    }

  public:
    void addPipe(ll u, ll v, ll cap){
      adj[u].push_back(pipes.size());
      pipes.push_back(Pipe(v, cap));

      adj[v].push_back(pipes.size());
      pipes.push_back(Pipe(u, 0));
    }

    void addSource(ll u, ll cap){
      addPipe(0, u, cap);
    }

    void addSink(ll u, ll cap){
      addPipe(u, sz-1, cap);
    }

    ll max(){
      ll maxFlow = 0;

      while(bfs()){
        maxFlow += dfs();
      }

      return maxFlow;
    }
};
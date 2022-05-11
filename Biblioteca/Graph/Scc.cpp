struct SCC{
    private:
        vector<vector<ll>> adj;
        vector<vector<ll>> rev;
        vector<vector<ll>> components;
        ll sz;

        void makePath(ll node, stack<ll> &q, vector<bool> &visit){
            if(visit[node]) return;
            visit[node] = true;

            for(auto next: adj[node]){
                makePath(next, q, visit);
            }

            q.push(node);
        }

    public:
        SCC(ll _sz){
            sz = _sz;
            adj.resize(sz);
            rev.resize(sz);
        }

        void addEdge(ll u, ll v, bool base = false){
            if(base) u--, v--;

            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        void build(){
            stack<ll> finish;
            vector<bool> visit(sz, false);

            for(int i = 0 ; i < sz ; i++){
                makePath(i, finish, visit);
            }

            // Cleaning visit array to reuse one the second part
            visit.clear();
            visit.resize(sz, false);

            ll node, idx = -1;
            while(!finish.empty()){
                node = finish.top();
                finish.pop();

                if(visit[node]) continue;
                components.push_back({});
                idx++;

                queue<ll> q;

                visit[node] = true;
                q.push(node);

                while(!q.empty()){
                    node = q.front();
                    q.pop();

                    components[idx].push_back(node);

                    for(auto next: rev[node]){
                        if(visit[next]) continue;
                        visit[next] = true;

                        q.push(next);
                    }
                }
            }
        }

        ll qttComponents(){
            return components.size();
        }

        void printComponents(){
            cout << "-------Componentes-------" << endl;
            for(auto vec: components){
                for(auto val: vec) cout << val << " ";
                cout << endl;
            }
            cout << "-------------------------" << endl;
        }
};
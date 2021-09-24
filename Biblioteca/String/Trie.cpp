struct Trie{
    private:
        vector<vll> trie;
        vll terminal;
        ll z;

        ll get_id(char ch){
            return ch-'a';
        }


    Trie(ll ms, ll sigma){
        trie.resize(ms*sigma, vll(sigma, -1));
        terminal(ms*sigma);
        z = 1;
    }

    void insert(string &str){
        ll cur = 0;
        for(auto ch: str){
            ll id = get_id(ch);
            if(trie[cur][id] == -1){
                trie[cur][id] = z++;
            }
            cur = trie[cur][id];
        }

        terminal[cur]++;
    }

    ll count(string &str){
        ll cur = 0;
        for(auto ch: str){
            ll id = get_id(ch);
            if(trie[cur][id] == -1){
                return 0;
            }
            cur = trie[cur][id];
        }

        return terminal[cur];
    }
};
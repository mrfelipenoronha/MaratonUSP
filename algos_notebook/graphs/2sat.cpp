/*
    2 SAT
    O(n + m) - #variables + #clauses
*/

#define maxn 112345 // 2*(#MAXelements)

struct TwoSat {

    vector<int> low, pre, id;
    int clk = 0, cnt = 0, numSCC = 0; // cnt == 2*(#elements) 
    vector<bool> eval;

    vector<vector<int>> adj;
    stack<int> nodes;

    TwoSat(int _maxn): low(_maxn, 0), pre(_maxn, -1), id(_maxn, 0), eval(_maxn, 0), adj(_maxn, vector<int>()) {}

    void dfs(int v){
        nodes.push(v);
        pre[v] = low[v] = clk++;
        for (auto x: adj[v]) {
            if (pre[x] == -1) dfs(x);
            low[v] = min(low[v], low[x]);
        }
        if (low[v] == pre[v]) {
            while (1) {
                int j = nodes.top();
                nodes.pop();
                id[j] = numSCC;
                low[j] = INF;
                if (j == v) break;
            }
            numSCC++;
        }
    }

    int neg(int i) {
        if (i <= cnt/2) return i + cnt/2;
        return i - cnt/2; 
    }

    void add_imp(int i, int j) {
        adj[i].pb(j);
    }

    void add_or(int i, int j) {
        add_imp(neg(i), j);
        add_imp(neg(j), i);
    }

    void add_xor(int i, int j) {
        add_or(i, j);
        add_or(neg(i), neg(j));
    }

    void force_var(int i) {
        add_imp(neg(i), i);
    }

    bool sat() {
        for (int i = 1; i <= cnt; i++)
            if (pre[i] == -1) dfs(i);
        for (int i = 1; i <= cnt/2; i++) {
            if (id[i] == id[neg(i)]) return 0;
            eval[i] = (id[i] < id[neg(i)]);
            eval[neg(i)] = !eval[i];
        }
        return 1;
    }
};

int main(){

    TwoSat sat(maxn);
    sat.cnt = 2*n; // set up

    // REMEMBER IT IS 1 INDEXED
}
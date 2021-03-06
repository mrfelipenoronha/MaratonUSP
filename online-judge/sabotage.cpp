#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

struct FlowEdge {
    int u, v;
    long long cap, flow = 0;
};

vector<FlowEdge> edges;
vector<vector<int>> adj;
int n, m, cnt; 
int s = 1, t = 2;
vector<int> level, ptr, vis;
queue<int> q;
 
void init() {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
    vis.resize(n);
}

void uninit() {
    edges.clear();
    adj.clear();
    n = 0, m = 0, cnt = 0; 
    level.clear();
    ptr.clear();
}
 
void add_edge(int u, int v, ll cap) {
    edges.pb({u, v, cap});
    edges.pb({v, u, 0ll});
    adj[u].pb(cnt++);
    adj[v].pb(cnt++);
}
 
bool bfs() {
    fill(all(vis), 0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (int id : adj[u]) {
            if (edges[id].cap - edges[id].flow < 1)
                continue;
            if (level[edges[id].v] != -1)
                continue;
            level[edges[id].v] = level[u] + 1;
            q.push(edges[id].v);
        }
    }
    return level[t] != -1;
}
 
ll dfs(int u, ll pushed) {
    if (pushed == 0)
        return 0ll;
    if (u == t)
        return pushed;
    for (int& cid = ptr[u]; cid < adj[u].size(); cid++) {
        int id = adj[u][cid];
        int v = edges[id].v;
        if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
            continue;
        ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
        if (tr == 0)
            continue;
        edges[id].flow += tr;
        edges[id^1].flow -= tr;
        return tr;
    }
    return 0;
}
 
ll dinic() {
    ll f = 0;
    while (true) {
        fill(all(level), -1);
        level[s] = 0;
        q.push(s);
        if (!bfs()) break;
        fill(all(ptr), 0);
        while (ll pushed = dfs(s, LINF)) 
            f += pushed;
    }

    for (auto e: edges) {
        int u = e.u;
        int v = e.v;
        if (vis[u] && !vis[v] && e.cap) 
            cout << u << " " << v << endl;
    }
    return f;
}

int main(){
    fastio;

    while (cin >> n >> m && n && m) {

        n += 10;
        init();

        int u, v;
        ll c;
        fr (i, m) {
            cin >> u >> v >> c;
            add_edge(u, v, c);
            add_edge(v, u, c);
        }

        dinic();
        cout << endl;

        uninit();
    }
}

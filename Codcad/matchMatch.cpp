// codcad.com/problem/147

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define MAXN 50009 
#define MAXL 18

vector<int> adj[MAXN]; // Adj 
int parent[MAXN];
int lvl[MAXN];
int anc[MAXN][MAXL];
int c[MAXN];
int par[MAXN];

void dfs(int u){

	for (auto v : adj[u]){

		if (lvl[v] != -1) continue;

		parent[v] = u; 
		lvl[v] = lvl[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v){

	if (lvl[u] < lvl[v]) swap(u, v);

	for (int i = MAXL-1; i >= 0; i--)
		if (lvl[u] - (1 << i) >= lvl[v])
			u = anc[u][i];

	if (u == v) return v;

	for (int i = MAXL-1; i >= 0; i--)
		if (anc[u][i] != -1 && anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}

	return anc[u][0];
}

int main(){

	fastio;

	int N;
	cin >> N;

	frr(i, N){
		int x;
		cin >> x;

		if(c[x]){
			par[i] = c[x];
			par[c[x]] = i;
		}
		c[x] = i;
	}

	fr(i, N-1){
		int a, b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = 0; i < N+4; i++)
		lvl[i] = -1;

	int root = 1; 
	lvl[root] = 0;

	dfs(root);

	for (int i = 0; i < N+3; i++)
		for (int j = 0; j < MAXL; j++)
			anc[i][j] = -1;

	for (int i = 1; i <= N; i++)
		anc[i][0] = parent[i];

	for (int j = 1; j < MAXL; j++)
		for (int i = 1; i <= N; i++)
			if (anc[i][j-1] != -1)
				anc[i][j] = anc[anc[i][j-1]][j-1];

	vector<bool> aux(N+1, false);
	ll ans = 0ll;
	frr(i, N){
		if (aux[i]) continue;
		aux[i] = aux[par[i]] = 1;
		ans += (long long int)(lvl[i] + lvl[par[i]] - 2*lvl[lca(i, par[i])]);
	}

	cout << ans << endl;
}


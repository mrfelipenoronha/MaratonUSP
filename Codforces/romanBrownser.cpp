// codeforces.com/contest/1100/problem/A

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

int main(){
	fastio
	
	int n, k;
	cin >> n >> k;

	int a[n+1], ace = 0, acs = 0;
	frr(i, n){
		cin >> a[i];
		if (a[i] > 0) ace++;
		else acs++;
	}

	int ans = 0;
	frr(i, k){
		int auxe = 0, auxs = 0;
		for (int j = i; j <= n; j += k){
			if (a[j] > 0) auxe++;
			else auxs++;
		}
		ans = max(ans, abs((ace-auxe)-(acs-auxs)));
	}

	cout << ans << endl;
}

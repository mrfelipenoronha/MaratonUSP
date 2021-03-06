// www.codechef.com/JAN17/problems/CATSDOGS

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

int main(){
	fastio

	int t;
	cin >> t;

	while (t--) {

		ll c, d, l;
		cin >> c >> d >> l;

		if (c*4ll + d*4ll < l || (l%4ll != 0ll)){
			p(no);
			continue;
		}

		ll aux = min(c, 2ll*d);

		if (4ll*(c-aux) + 4ll*d > l){
			p(no);
			continue;
		}

		p(yes);
	}
}

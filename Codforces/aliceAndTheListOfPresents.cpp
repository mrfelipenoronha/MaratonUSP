//codeforces.com/contest/1236/problem/B

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

const ll mod = 1e9+7;

ll fastexp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2;
	}
	return ans;
}

int main(){
    fastio;

    ll n, m;
    cin >> n >> m;

    ll ans = fastexp(2, m);
    ans--;
    ans = fastexp(ans, n);

    cout << ans << endl;
}

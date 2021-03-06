//codeforces.com/contest/1176/problem/B

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

		int n;
		cin >> n;

		int a, c1 = 0, c2 = 0, c3 = 0;
		while (n--) {
			cin >> a;

			c1 += ((a%3) == 1);
			c2 += ((a%3) == 2);
			c3 += ((a%3) == 0);
		}

		while (c2 && c1)
			c2--, c1--, c3++;

		cout << c3 + c2/3 + c1/3 << endl;
	}

}

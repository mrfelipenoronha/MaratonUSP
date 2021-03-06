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

	int n; cin >> n;

	unordered_map<string, int> freq;

	bool flag = true;

	vector<string> ans;

	while(n--){

		string s; cin >> s;
		freq[s]++;
		if(freq[s]>1 && s.size()>=4){
			ans.pb(s);
			flag = false;
		}
	}

	if(flag)
		cout << "SAFO" << "\n";
	else{
		cout << ans.size() << "\n";
		for(auto x : ans)
			cout << x << "\n";
	}

}

//codeforces.com/contest/1368/problem/D

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    ll n;
    cin >> n;

    ll a[n];
    fr(i, n) cin >> a[i];

    ll cnt[23];
    ms(cnt, 0ll);

    fr(i,n) 
        fr(bit, 23) 
            if (a[i]&(1<<bit))
                cnt[bit]++;
    
    ll ans = 0;
    while (1) {
        ll x = 0ll;
        fr(bit, 23) 
            if (cnt[bit]) {
                cnt[bit]--;
                x |= (1<<bit);
            }
        if (!x) break;
        ans += x*x;
    }

    p(ans);
}

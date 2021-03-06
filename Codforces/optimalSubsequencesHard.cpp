//codeforces.com/contest/1262/problem/D2

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


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds ;
typedef tree<pii, null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    fastio;

    int n, m;
    cin >> n;

    pii a[n];
    fr(i, n) cin >> a[i].f, a[i].s = -i;
    sort(a, a+n);
    reverse(a, a+n);

    int idx = 0;

    cin >> m;

    vector< pair<pii, int> > qrs;
    vi ans(m);

    fr(i, m) {
        
        int k, pos;
        cin >> k >> pos;
        
        qrs.pb({{k,pos}, i});
    }
    sort(all(qrs));

    ordered_set sub;
    for (auto q: qrs) {

        int k = q.f.f;
        int p = q.f.s;
        int ans_i = q.s;

        while (k > sub.size()) {
            pii x = a[idx++];
            sub.insert({-x.s, x.f});
        }

        auto it = sub.find_by_order(p-1);
        ans[ans_i] = (*it).s;
    }

    for (auto x: ans) p(x);
}

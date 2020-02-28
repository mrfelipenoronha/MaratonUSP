//codeforces.com/contest/1311/problem/B

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

int main(){
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        fr(i, n) cin >> a[i];
        int p[m]; // tem q acabar
        fr(i, m) cin >> p[i], p[i]--;
        sort(p, p+m);
    
        vector<pii> aux;
        int lst = -1;
        fr(i, m) {
            if (lst == -1) {
                lst = p[i];
                continue;
            }
            if (p[i] == p[i-1]+1) continue;
            aux.pb({lst, p[i-1]+1});
            lst = p[i];
        }
        if (lst != -1) aux.pb({lst, p[m-1]+1});
    
        for (auto gap: aux) 
            sort(a+gap.f, a+gap.s+1);
        if (is_sorted(a, a+n)) p("YES");
        else p("NO");
    }
}

//codeforces.com/contest/1382/problem/A

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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        fr(i, n) cin >> a[i];
        fr(i, m) cin >> b[i];

        map<int, int> mp;
        fr(i, n) mp[a[i]] = i+1;
        fr(i, m) {
            if (mp.find(b[i]) != mp.end()) {
                p("YES");
                cout << 1 << " " << b[i] << endl;
                goto fim;
            }
        }

        p("NO");
        fim:;
    }
}

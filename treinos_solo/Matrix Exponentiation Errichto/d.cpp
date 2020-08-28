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

const ll mod = 1000000007; // To be defined
typedef vector< vector<ll> > matrix;

// defining function to multiplicate a matrix
matrix operator*(matrix &a, matrix &b) {
    int ai = a.size(); 
    int aj = a[0].size();
    int bj = b[0].size();
    matrix aux(ai, vector<ll>(bj, 0ll));
    for (int k = 0; k < aj; k++) 
        for (int i = 0; i < ai; i++) 
            for (int j = 0; j < bj; j++) {
                aux[i][j] += a[i][k]*b[k][j];
                if (aux[i][j] > 8ll*mod*mod) 
                    aux[i][j] -= 8ll*mod*mod;
            }
    for (int i = 0; i < ai; i++) 
        for (int j = 0; j < bj; j++)
            aux[i][j] %= mod;
    return aux;
}

// idendity matrix
matrix id(int x) {
    matrix v(x, vector<ll>(x));
    for (int i = 0; i < x; i++) v[i][i] = 1ll;
    return v;
}

// exponentiate a matrix 'a' by a factor 'x'
void exp(matrix &a, ll x) {
    matrix ans = id(a.size());
    while (x) {
        if (x%2) ans = ans*a;
        a = a*a;
        x /= 2;
    }
    a = ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    matrix v(n, vector<ll>(n, 0));
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = 1;
    }

    exp(v, k);
    ll ans = 0ll;
    for (auto xx: v) 
        for (auto x: xx) 
            ans = (ans+x)%mod;

    p(ans);
}

//codeforces.com/contest/1334/problem/A

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

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, deu = 1;
        cin >> n;

        pii lst = {-1, -1};
        fr(i, n) {
            int c, p;
            cin >> p >> c;
            if (p < lst.f) deu = 0;
            if (c < lst.s) deu = 0;
            if (c-lst.s > p-lst.f) deu = 0;
            if (c > p) deu = 0;
            lst = {p, c};
        }

        if (deu) p("YES");
        else p("NO");
    }
}

// https://codeforces.com/contest/1056/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int r[109];

int main(){
	int n;
	cin >> n;
	int h;
	fr(i, n){
		cin >> h;
		fr(j, h){
			int x;
			cin >> x;
			r[x]++;
		}
	}
	frr(i,100){
		if (r[i] == n)
			cout << i << " ";
	}
	cout << endl;
}

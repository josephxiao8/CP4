#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vi> adj;
vi color;

void dfs(int start){
	for(auto u:adj[start]){
		if(color[u]==0){
			color[u]=3-color[start];
			dfs(u);
		}
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin>>n;
adj=vector<vi>(n);
vpi edj;
for(int i=0; i<n-1; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
	edj.pb(mp(a,b));
}

color=vi(n,0);
for(int i=0; i<n; i++){
	if(color[i]==0){
		color[i]=1;
		dfs(i);
	}
}

for(auto x:edj){
	int a,b;
	tie(a,b)=x;
	if(color[a]==1) cout<<1<<endl;
	else cout<<0<<endl;
}

return 0;
}

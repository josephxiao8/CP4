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


vector<vpl> adj;
vector<bool> visited;
ll counter;
ll ppa;

void dfs(ll start){
	visited[start]=true;
	for(auto u:adj[start]) {
		ll b,c;
		tie(b,c)=u;
		if(!visited[b] && c==ppa) {
			counter++;
			dfs(b);
		}
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ll n,m;
while(cin>>n>>m, !(n==0 && m==0)){
	adj.clear();
	adj=vector<vpl>(n);
	ppa=LONG_LONG_MIN;
	for(ll i=0; i<m; i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
		ppa=max(ppa,c);
	}
	
	visited.clear();
	visited=vector<bool>(n,false);
	ll ans=0;
	for(ll i=0; i<n; i++){
		if(!visited[i]){
			counter=0;
			dfs(i);
			ans=max(ans,counter+1);
		}
	}
	cout<<ans<<endl;
}

return 0;	
}

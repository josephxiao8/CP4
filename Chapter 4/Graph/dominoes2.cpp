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


vector<bool> visited;
vector<vi> adj;

void dfs(int start){
	for(auto u:adj[start]){
		if(!visited[u]) {
			visited[u]=true;
			dfs(u);
		}
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int t;
cin>>t;
while(t--){
	int n,m,l;
	cin>>n>>m>>l;
	adj.clear();
	visited.clear();
	adj=vector<vi>(n);
	visited=vector<bool>(n,false);
	
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
	}
	
	for(int i=0; i<l; i++){
		int temp;
		cin>>temp;
		temp--;
		visited[temp]=true;
		dfs(temp);
	}
	
	int ans=0;
	for(auto x:visited){
		if(x) ans++;
	}
	cout<<ans<<endl;
}

return 0;	
}

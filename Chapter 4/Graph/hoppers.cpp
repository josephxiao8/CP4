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
vector<bool> visited;
vi color;
bool bip;

void dfs(int start){
	for(auto u:adj[start]){
		if(!visited[u]) {
			visited[u]=true;
			color[u]=3-color[start];
			dfs(u);
		}
		else if(color[u]==color[start]) bip=false;
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin>>n>>m;

adj=vector<vi>(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

int cc=0;
int bips=0;
visited=vector<bool>(n,false);
color=vi(n,0);
for(int i=0; i<n; i++){
	if(!visited[i]){
		visited[i]=true;
		color[i]=1;
		bip=true;
		dfs(i);
		cc++;
		if(bip) bips++;
	}
}

if(cc-bips>0) cout<<cc-1;
else cout<<cc;
return 0;
}

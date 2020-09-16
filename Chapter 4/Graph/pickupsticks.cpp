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


vi ans;
vector<vi> adj;
vi color;
bool possible=true;

void dfs(int start){
	if(!possible) return;
	for(auto u:adj[start]){
		if(!possible) return;
		if(color[u]==0){
			color[u]=1;
			dfs(u);
		}
		else if(color[u]==1){
			possible=false;
		}
	}
	ans.pb(start);
	color[start]=2;
	return;
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
}

color=vi(n,0);
for(int i=0; i<n; i++){
	if(color[i]==0){
		color[i]=1;
		dfs(i);
		
		if(!possible){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
}

reverse(ans.begin(), ans.end());
for(auto x:ans) cout<<x+1<<endl;

return 0;
}

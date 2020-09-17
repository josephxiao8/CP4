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
int ones, twos;
int n;

void dfs(int start){
	for(auto u:adj[start]){
		if(u>=n) continue;
		if(color[u]==0){
			color[u]=3-color[start];
			if(!(ones==0) && color[u]==1) ones++;
			else if(!(ones==0)) twos++;
			dfs(u);
		}
		else if(color[u]==color[start]){
			ones=0;
			twos=0;
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
	cin>>n;
	adj.clear();
	adj=vector<vi>(n);
	for(int i=0; i<n; i++){
		int p;
		cin>>p;
		while(p--){
			int temp;
			cin>>temp;
			temp--;
			if(temp>=n) continue;
			adj[i].pb(temp);
			adj[temp].pb(i);
		}
	}
	
	int ans=0;
	color.clear();
	color=vi(n,0);
	for(int i=0; i<n; i++){
		if(color[i]==0){
			color[i]=1;
			ones=1;
			twos=0;
			dfs(i);
			ans+=max(ones,twos);
		}
	}
	cout<<ans<<"\n";
}

return 0;
}

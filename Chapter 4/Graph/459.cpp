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

void dfs(int start){
	visited[start]=true;
	for(auto u:adj[start]) {
		if(!visited[u]) dfs(u);
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int t;
cin>>t;
while(t--){
	char c;
	cin>>c;
	cin.ignore();
	
	adj.clear();
	adj=vector<vi>(c-'A'+1);
	string s;
	while(getline(cin,s), s!=""){
		adj[s[0]-'A'].pb(s[1]-'A');
		adj[s[1]-'A'].pb(s[0]-'A');
	}
	
	visited.clear();
	visited=vector<bool>(c-'A'+1,false);
	int ans=0;
	for(int i=0; i<c-'A'+1; i++){
		if(!visited[i]){
			ans++;
			dfs(i);
		}
	}
	
	cout<<ans<<endl;
	if(t!=0) cout<<endl;
}

return 0;	
}

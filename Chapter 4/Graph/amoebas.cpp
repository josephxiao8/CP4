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


vector<vector<char> > grid;
vector<vector<bool> > visited;
vi dy={1,1,1,0,0,-1,-1,-1};
vi dx={1,0,-1,1,-1,1,0,-1};
int m,n;

void dfs(int y, int x){
	for(int i=0; i<8; i++){
		int a=x+dx[i];
		int b=y+dy[i];
		if(a<0 || a>=n || b<0 || b>=m) continue;
		if(!visited[b][a]) {
			visited[b][a]=true;
			dfs(b,a);
		}
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

cin>>m>>n;
grid.clear();
grid=vector<vector<char> >(m, vector<char>(n));
visited.clear();
visited=vector<vector<bool> >(m,vector<bool>(n,false));
for(int j=0; j<m; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
		if(grid[j][i]=='.') visited[j][i]=true;
	}
}

int ans=0;
for(int j=0; j<m; j++){
	for(int i=0; i<n; i++){
		if(!visited[j][i]){
			visited[j][i]=true;
			ans++;
			dfs(j,i);
		}
	}
}

cout<<ans;
return 0;	
}

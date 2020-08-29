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


vector<vector<bool> > visited;
vector<vi> grid;
vi dy={1,1,1,0,0,-1,-1,-1};
vi dx={0,1,-1,1,-1,0,1,-1};
int n;

void dfs(int y, int x){
	for(int i=0; i<8; i++){
		int a=x+dx[i];
		int b=y+dy[i];
		if(a<0 || a>=n || b<0 || b>=n) continue;
		if(grid[b][a]==1 && !visited[b][a]) {
			visited[b][a]=true;
			dfs(b,a);
		}
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int casenum=1;
while(cin>>n){
	grid.clear();
	grid=vector<vi>(n, vi(n));
	for(int j=0; j<n; j++){
		string s;
		cin>>s;
		for(int i=0; i<n; i++){
			grid[j][i]=s[i]-'0';
		}
	}
	
	int ans=0;
	visited.clear();
	visited=vector<vector<bool> >(n, vector<bool>(n,false));
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(grid[j][i]==1 && !visited[j][i]){
				ans++;
				visited[j][i]=true;
				dfs(j,i);
			}
		}
	}
	cout<<"Image number "<<casenum++<<" contains "<<ans<<" war eagles."<<endl;
}

return 0;	
}

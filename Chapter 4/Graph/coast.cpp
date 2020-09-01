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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin>>n>>m;
vector<vector<char> > grid(n+2, vector<char>(m+2,'0'));
vector<vector<bool> > visited(n+2, vector<bool>(m+2,false));
for(int j=1; j<n+1; j++){
	string temp;
	cin>>temp;
	for(int i=1; i<m+1; i++){
		grid[j][i]=temp[i-1];
	}
}

int ans=0;
vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
for(int j=0; j<n+2; j++){
	for(int i=0; i<m+2; i++){
		if((j==0 || j==n+1 || i==0 || i==m+1) && grid[j][i]=='0' && !visited[j][i]){
			visited[j][i]=true;
			queue<pi> q;
			q.push(mp(j,i));
			while(!q.empty()){
				int a,b;
				tie(b,a)=q.front(); q.pop();
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || c>=m+2 || d<0 || d>=n+2) continue;
					if(grid[d][c]=='0' && !visited[d][c]){
						visited[d][c]=true;
						q.push(mp(d,c));
					}
					else if(grid[d][c]=='1') ans++;
				}		
			}
		}
	}
}

cout<<ans;
return 0;	
}

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

int x,y;
cin>>x>>y;

vector<vi> grid(y,vi(x));
for(int j=0; j<y; j++){
	for(int i=0; i<x; i++){
		cin>>grid[j][i];
	}
}

vi dy={1,-1,0,0};
vi dx={0,0,1,-1};

vector<vector<bool> > visited(y,vector<bool>(x,false));
int ans=0;
for(int j=0; j<y; j++){
	for(int i=0; i<x; i++){
		if(!visited[j][i]){
			visited[j][i]=true;
			queue<pi> q;
			q.push(mp(j,i));
			int counter=0;
			bool good=true;
			while(!q.empty()){
				counter++;
				int a,b;
				tie(b,a)=q.front(); q.pop();
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || x<=c || d<0 || y<=d) continue;
					if(grid[d][c]<grid[b][a]){
						good=false;
					}
					else if(grid[d][c]==grid[b][a] && !visited[d][c]){
						visited[d][c]=true;
						q.push(mp(d,c));
					}
				}
			}
			if(good) ans+=counter;
		}
	}
}

cout<<ans;
return 0;	
}

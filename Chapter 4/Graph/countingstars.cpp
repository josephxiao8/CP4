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

int m,n, casenum=1;
while(cin>>m>>n){
	vector<vector<bool> > visited(m,vector<bool>(n));
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			char temp;
			cin>>temp;
			if(temp=='#') visited[j][i]=true;
		}
	}
	
	int ans=0;
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(!visited[j][i]){
				ans++;
				visited[j][i]=true;
				queue<pi> q;
				q.push(mp(j,i));
				vi dy={1,-1,0,0};
				vi dx={0,0,1,-1};
				while(!q.empty()){
					int a,b;
					tie(b,a)=q.front(); q.pop();
					for(int k=0; k<4; k++){
						int c=a+dx[k];
						int d=b+dy[k];
						if(c<0|| c>=n || d<0 || d>=m) continue;
						else if(!visited[d][c]){
							visited[d][c]=true;
							q.push(mp(d,c));
						}
					}
				}
			}
		}
	}
	cout<<"Case "<<casenum++<<": "<<ans<<endl;
}

return 0;	
}

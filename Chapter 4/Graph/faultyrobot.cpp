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
vector<vi> adj(n);
vector<vi> forced(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	if(a>0) adj[a-1].pb(b-1);
	else forced[(-a)-1].pb(b-1);
}

queue<pi> q;
q.push(mp(0,0));
vector<bool> visited(n,false);
visited[0]=true;
set<int> sett;

while(!q.empty()){
	int start=q.front().f; 
	int state=q.front().s;
	q.pop();
	if(state==0){
		if(forced[start].size()==0) sett.insert(start);
		else {
			if(!visited[forced[start].front()]){
				q.push(mp(forced[start].front(),0));
				visited[forced[start].front()]=true;
			}
		}
		for(auto u:adj[start]) {
			if(!visited[u]) q.push(mp(u,1));
		}
	}
	else{
		if(forced[start].size()==0){
			sett.insert(start);
		}
		else if(!visited[forced[start].front()]){
			q.push(mp(forced[start].front(),1));
			visited[forced[start].front()]=true;
		}
	}
}

cout<<sett.size();
return 0;
}

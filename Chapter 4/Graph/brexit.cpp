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

int c,p,x,l;
cin>>c>>p>>x>>l;
x--;
l--;

vector<vi> adj(c);
vi degree(c,0);
vi left(c,0);
vector<bool> left_already(c,false);
for(int i=0; i<p; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	degree[a]++;
	degree[b]++;
	adj[a].pb(b);
	adj[b].pb(a);
}

queue<int> q;
q.push(l);
left_already[l]=true;
while(!q.empty()){
	int start=q.front(); q.pop();
	for(auto u:adj[start]){
		left[u]++;
		if(!left_already[u] && 2*left[u]>=degree[u]) {
			q.push(u);
			left_already[u]=true;
		}
	}
}

if(left_already[x]) cout<<"leave";
else cout<<"stay";
return 0;
}

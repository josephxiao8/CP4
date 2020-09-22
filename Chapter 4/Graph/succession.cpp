#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ldb;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<pl> pq;
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
string founder;
cin>>n>>m>>founder;

int counter=1;
map<string,int> mapp;
map<int,string> mapp_back;
vector<vi> adj(151);
vector<vi> adj2(151);
for(int i=0; i<n; i++){
	string a,b,c;
	cin>>a>>b>>c;
	if(mapp[a]==0){
		mapp_back[counter]=a;
		mapp[a]=counter++;
	}
	if(mapp[b]==0){
		mapp_back[counter]=b;
		mapp[b]=counter++;
	}
	if(mapp[c]==0){
		mapp_back[counter]=c;
		mapp[c]=counter++;
	}
	adj[mapp[a]].pb(mapp[b]);
	adj[mapp[a]].pb(mapp[c]);
	adj2[mapp[b]].pb(mapp[a]);
	adj2[mapp[c]].pb(mapp[a]);
}

vector<bool> potential(counter,false);
for(int i=0; i<m; i++){
	string s;
	cin>>s;
	potential[mapp[s]]=true;
}

vector<double> blood(counter,-(1.0));
vector<bool> visited(counter,false);
queue<int> q;
for(int i=1; i<counter; i++){
	if(adj[i].size()==0){
		visited[i]=true;
		q.push(i);
		if(i==mapp[founder]) blood[i]=1.0;
		else blood[i]=0.0;
	}
}

while(!q.empty()){
	int start=q.front(); q.pop();
	for(auto u:adj2[start]){
		int a=adj[u][0];
		int b=adj[u][1];
		if(blood[a]==-1.0 || blood[b]==-1.0) continue;
		blood[u]=blood[a]/2.0+blood[b]/2.0;
		q.push(u);
	}
}

double maxx=DBL_MIN;
int ans;
for(int i=1; i<counter; i++){
	if(blood[i]>=maxx && potential[i]) {
		ans=i;
		maxx=blood[i];
	}
}

cout<<mapp_back[ans];
return 0;
}



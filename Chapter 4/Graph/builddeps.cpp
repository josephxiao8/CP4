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
vi ans;

void toposort(int start){
	for(auto u:adj[start]){
		if(!visited[u]){
			visited[u]=true;
			toposort(u);
		}
	}
	ans.pb(start);
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n,counter=1;
cin>>n;
cin.ignore();
map<string,int> mapp;
map<int,string> mapp_back;
adj=vector<vi>(n+1);
for(int i=0; i<n; i++){
	string s;
	getline(cin,s);
	vector<string> files;
	string temp="";
	for(auto x:s){
		if(x==':' || x==' '){
			if(temp!="") files.pb(temp);
			temp="";
		}
		else temp+=x;
	}
	if(temp!="") files.pb(temp);
	
	if(mapp[files[0]]==0){
		mapp[files[0]]=counter;
		mapp_back[counter]=files[0];
		counter++;
	}
	for(int i=1; i<int(files.size()); i++){
		if(mapp[files[i]]==0){
			mapp[files[i]]=counter;
			mapp_back[counter]=files[i];
			counter++;
		}
		adj[mapp[files[i]]].pb(mapp[files[0]]);
	}
}

string c;
cin>>c;
visited=vector<bool>(n+1,false);
visited[mapp[c]]=true;
toposort(mapp[c]);
reverse(ans.begin(), ans.end());
for(auto x:ans) cout<<mapp_back[x]<<endl;
return 0;
}

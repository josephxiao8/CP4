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
vector<bool> appears;
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

void split(vector<string> v){
	vector<char> v2;
	vector<string> v3;
	for(int i=0; i<v.size(); i++){
		int id=i;
		for(int j=i; j<v.size() && v[j][0]==v[i][0]; j++){
			id=j;
			if(v[j].size()>1) v3.pb(v[j].substr(1));
		}
		v2.pb(v[i][0]);
		i=id;
		if(v3.size()>1) split(v3);
		v3.clear();
	}
	for(int i=0; i<v2.size()-1; i++){
		adj[v2[i]-'A'].pb(v2[i+1]-'A');
		appears[v2[i]-'A']=true;
		appears[v2[i+1]-'A']=true;
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

string s;
while(cin>>s){
	vector<string> v;
	v.pb(s);
	while(cin>>s, s!="#") v.pb(s);
	appears.clear();
	appears=vector<bool>(26,false);
	adj.clear();
	adj=vector<vi>(26);
	split(v);

	visited.clear();
	visited=vector<bool>(26,false);
	ans.clear();
	for(int i=0; i<26; i++){
		if(!visited[i] && appears[i]){
			visited[i]=true;
			toposort(i);
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto x:ans) cout<<char(65+x);
	cout<<endl;
}

return 0;
}

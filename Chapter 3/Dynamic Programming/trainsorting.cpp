#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
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

int n;
cin>>n;
vi v(n);
for(int i=0; i<n; i++) cin>>v[i];

int ans=0;
for(int i=0; i<n; i++){
	set<int> sett;
	int ans1=0;
	for(int j=n-1; j>i; j--){
		if(v[j]>=v[i]) continue;
		auto it=sett.lb(v[j]);
		if(it!=sett.end()) sett.erase(it);
		sett.insert(v[j]);
		ans1=sett.size();
	}
	
	sett.clear();
	int ans2=0;
	for(int j=i+1; j<n; j++){
		if(v[j]<=v[i]) continue;
		auto it=sett.lb(v[j]);
		if(it!=sett.end()) sett.erase(it);
		sett.insert(v[j]);
		ans2=sett.size();
	}

	ans=max(ans, ans1+ans2+1);
}

cout<<ans;
return 0;
}

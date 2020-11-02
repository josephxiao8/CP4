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
while(cin>>n){
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	set<int> sett;
	sett.insert(v[0]);
	vi dp1(n);
	dp1[0]=1;
	for(int i=1; i<n; i++){
		auto it=sett.lb(v[i]);
		if(it!=sett.end()) sett.erase(it);
		sett.insert(v[i]);
		dp1[i]=sett.size();
	}
	
	sett.clear();
	sett.insert(v[n-1]);
	vi dp2(n);
	dp2[n-1]=1;
	for(int i=n-2; i>=0; i--){
		auto it=sett.lb(v[i]);
		if(it!=sett.end()) sett.erase(it);
		sett.insert(v[i]);
		dp2[i]=sett.size();
	}
	
	int ans=1;
	for(int i=0; i<n; i++) ans=max(ans, 2*min(dp1[i],dp2[i])-1);
	cout<<ans<<endl;
}

return 0;	
}




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
while(cin>>n, n!=0){
	vpi v;
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		v.pb(mp(a,b));
	}
	sort(v.begin(), v.end());
	
	int ans=1;
	vi dp(n,1);
	dp[0]=1;
	for(int i=1; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if(v[j].f<=v[i].f && v[j].s<=v[i].s) dp[i]=max(dp[i], 1+dp[j]);
		}
		ans=max(ans, dp[i]);
	}
	cout<<ans<<"\n";
}

cout<<"*\n";
return 0;
}

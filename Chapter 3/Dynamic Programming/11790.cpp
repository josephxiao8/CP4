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

int t, casenum=1;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vi h(n);
	vi w(n);
	for(int i=0; i<n; i++) cin>>h[i];
	for(int i=0; i<n; i++) cin>>w[i];
	
	int ans=w[0];
	vi dp(n);
	for(int i=0; i<n; i++){
		dp[i]=w[i];
		for(int j=i-1; j>=0; j--){
			if(h[i]>h[j]) dp[i]=max(dp[i], dp[j]+w[i]);
		}
		ans=max(ans, dp[i]);
	}
	
	reverse(h.begin(), h.end());
	reverse(w.begin(), w.end());
	int ans2=w[0];
	for(int i=0; i<n; i++){
		dp[i]=w[i];
		for(int j=i-1; j>=0; j--){
			if(h[i]>h[j]) dp[i]=max(dp[i], dp[j]+w[i]);
		}
		ans2=max(ans2, dp[i]);
	}
	
	if(ans>=ans2) cout<<"Case "<<casenum++<<". Increasing ("<<ans<<"). Decreasing ("<<ans2<<")."<<"\n";
	else cout<<"Case "<<casenum++<<". Decreasing ("<<ans2<<"). Increasing ("<<ans<<")."<<"\n";
	
}

return 0;
}

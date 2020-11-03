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

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vpi v(n);
	for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s; //price, weight
	
	int g, ans=0;
	cin>>g;
	for(int i=0; i<g; i++){
		int w;
		cin>>w;
		vi dp(w+1,0);
		for(int i=0; i<n; i++){
			for(int j=w; j>=0; j--){
				if(j-v[i].s>=0) dp[j]=max(dp[j-v[i].s]+v[i].f, dp[j]);
			}
		}
		int maxx=0;
		for(auto x:dp) maxx=max(maxx,x);
		ans+=maxx;
	}
	cout<<ans<<"\n";
}

return 0;
}

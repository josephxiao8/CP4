#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
 
typedef priority_queue<tuple<int,int,int> > pq;
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

ll t, casenum=1;
cin>>t;
while(t--){
	ll n,k;
	cin>>n>>k;
	
	vl a(n);
	for(ll i=0; i<n; i++) cin>>a[i];
	vl b(n);
	for(ll i=0; i<n; i++) {
		ll temp;
		cin>>temp;
		b[i]=temp-a[i];
	}
	sort(b.begin(), b.end());
	
	ll ans=0;
	for(ll i=0; i<n; i++){
		if(k>0 && b[i]<0) k--;
		else ans+=b[i];
	}
	
	if(ans>0) cout<<"Case "<<casenum++<<": "<<ans;
	else cout<<"Case "<<casenum++<<": No Profit";
	cout<<endl;
}

return 0;
}

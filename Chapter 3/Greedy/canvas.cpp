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
 
typedef priority_queue<int> pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> pqg;
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

ll t;
cin>>t;
while(t--){
	ll n;
	cin>>n;
	pqg q;
	for(ll i=0; i<n; i++){
		ll temp;
		cin>>temp;
		q.push(temp);
	}
	
	ll ans=0;
	while(q.size()>1){
		ll temp=0;
		temp+=q.top(); q.pop();
		temp+=q.top(); q.pop();
		q.push(temp);
		ans+=temp;
	}
	cout<<ans<<endl;
}

return 0;
}

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
 
typedef priority_queue<pi> pq;
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

ll n;
while(cin>>n && n!=0){
	ll two_max=ceil(log(n)/log(2));
	ll three_max=ceil(log(n)/log(3));
	ll ans=min(pow(2,two_max),pow(3,three_max));
	
	for(ll i=0; i<=two_max; i++){
		ll k=0;
		for(ll b=three_max/2; b>=1; b/=2){
			while(k+b<=three_max && pow(2,i)*pow(3,k+b)<n) k+=b;
		}
		ans=min(ans,ll(pow(2,i)*pow(3,k+1)));
	}
	cout<<ans<<"\n";
}

return 0;
}

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

ll n,m,a,c,x_0;
cin>>n>>m>>a>>c>>x_0;

vl v(n);
for(ll i=0; i<n; i++){
	v[i]=(a*x_0 +c)%m;
	x_0=v[i];
}

ll counter=0;
for(auto x:v){
	ll low=0, high=n-1;
	while(low<=high){
		ll mid=(low+high)/2;
		if(v[mid]==x){
			counter++;
			break;
		}
		else if(x>v[mid]) low=mid+1;
		else high=mid-1;
	}
}

cout<<counter;
return 0;
}

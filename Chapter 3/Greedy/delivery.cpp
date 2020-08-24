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

ll n,k;
cin>>n>>k;

vpl pos;
vpl neg;
for(ll i=0; i<n; i++){
	ll a,b;
	cin>>a>>b;
	if(a>0) pos.pb(mp(a,b));
	else if(a<0) neg.pb(mp(-1*a,b));
}
sort(pos.rbegin(), pos.rend());
sort(neg.rbegin(), neg.rend());

ll ans=0;
for(ll i=0; i<pos.size(); i++){
	bool cont=true;
	ll id;
	ll letters=0;
	for(ll j=i; j<pos.size(); j++){
		id=j;
		if(letters+pos[j].s<=k){
			letters+=pos[j].s;
			pos[j].s=0;
		}
		else{ 
			pos[j].s-=k-letters;
			letters=k;
			cont=false;
			break;
		}
	}
	ans+=2*pos[i].f;
	if(!cont)i=id-1;
	else i=id;
}

for(ll i=0; i<neg.size(); i++){
	bool cont=true;
	ll id;
	ll letters=0;
	for(ll j=i; j<neg.size(); j++){
		id=j;
		if(letters+neg[j].s<=k){
			letters+=neg[j].s;
			neg[j].s=0;
		}
		else{ 
			neg[j].s-=k-letters;
			letters=k;
			cont=false;
			break;
		}
	}
	ans+=2*neg[i].f;
	if(!cont)i=id-1;
	else i=id;
}

cout<<ans;
return 0;
}


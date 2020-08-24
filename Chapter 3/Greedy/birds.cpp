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

int l,d,n;
cin>>l>>d>>n;

vi v(n);
for(int i=0; i<n; i++) cin>>v[i];
sort(v.begin(), v.end());

int ans=0;
for(int i=0; i<=n; i++){
	if(i==0 && n!=0) ans+=(v[i]-6)/d;
	else if(i==n){
		if(n==0) ans+=(l-6-6)/d+1;
		else ans+=(l-6-v[n-1])/d;
	}
	else ans+=(v[i]-v[i-1])/d -1;
}

cout<<ans<<endl;
return 0;
}

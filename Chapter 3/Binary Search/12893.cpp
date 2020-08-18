#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
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


ll search(ll n){
	if(n==0) return 0;
	else return search(n/2)+(n%2);
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ll t;
cin>>t;
while(t--){
	ll n;
	cin>>n;
	cout<<search(n)<<endl;
}

return 0;
}

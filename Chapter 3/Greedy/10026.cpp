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

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	
	vector<pair<double,int> > v(n);
	for(int i=0; i<n; i++){
		double a,b;
		cin>>a>>b;
		v[i]=mp(a/b,i);
	}
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++) {
		cout<<v[i].s+1;
		if(i<n-1) cout<<" ";
	}
	if(t!=0)cout<<endl<<endl;
	else cout<<endl;
}

return 0;
}

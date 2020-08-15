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

int n,m;
while(cin>>n>>m && !(n==0 && m==0)){
	vector<vi> diag(n+m-1);
	for(int j=0; j<n; j++){
		for(int i=0; i<m; i++){
			int temp;
			cin>>temp;
			diag[i-j+(n-1)].pb(temp);
		}
	}
	
	int q;
	cin>>q;
	while(q--){
		int ans=0;
		int l,u;
		cin>>l>>u;
		for(int i=0; i<n+m-1; i++){
			int lower=lb(diag[i].begin(),diag[i].end(),l)-diag[i].begin();
			int upper=ub(diag[i].begin(), diag[i].end(),u)-diag[i].begin()-1;
			if(lower<=upper) ans=max(ans,upper-lower+1);
		}
		cout<<ans<<endl;
	}
	cout<<"-"<<endl;
}

return 0;
}

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

ll c, casenum=1;
cin>>c;
while(c--){
	int n,h,t_a,t_d;
	cin>>n>>h>>t_a>>t_d;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	sort(v.begin(), v.end());
	
	int ans=0;
	if(t_d<2*t_a){
		int l=0, r=n-1;
		while(l<r){
			if(v[l]+v[r]<h){
				l++;
				r--;
				ans+=t_d;
			}
			else{
				r--;
				ans+=t_a;
			}
		}
		if(l==r) ans+=t_a;
	}
	else ans=n*t_a;
	
	cout<<"Case "<<casenum++<<": "<<ans<<endl;
}

return 0;
}

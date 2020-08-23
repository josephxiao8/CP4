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

int n,g;
while(cin>>n>>g){
	int ans=0;
	vpi v;
	for(int i=0; i<n; i++){
		int s,r;
		cin>>s>>r;
		if(s>r) ans+=3;
		else{
			v.pb(mp(r-s+1, r-s));
			if(s==r) ans++;
		}
	}
	sort(v.begin(), v.end());
	
	int start=0;
	for(int i=0; i<v.size() && g>=v[i].f; i++){
		if(v[i].f==1) ans+=2;
		else ans+=3;
		g-=v[i].f;
		start++;
	}
	
	for(int i=start; i<v.size() && g>=v[i].s; i++){
		if(v[i].s!=0){
			ans++;
			g-=v[i].s;
		}
	}
	cout<<ans<<endl;
}

return 0;
}

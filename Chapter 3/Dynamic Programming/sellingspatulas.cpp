#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
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

int n;
while(cin>>n, n!=0){
	vector<long double> v(1440, -0.08);
	for(int i=0; i<n; i++){
		int a;
		long double b;
		cin>>a>>b;
		v[a]=v[a]+b;
	}
	
	long double ans=v[0];
	pair<long double,int> maxx={v[0],0}; //max profit, start time
	pi interval={0,0};
	
	for(int i=1; i<=1439; i++){
		if(maxx.f+v[i]>v[i]) maxx.f=maxx.f+v[i];
		else {
			maxx.f=v[i];
			maxx.s=i;
		}
		if(maxx.f>ans){
			ans=maxx.f;
			interval=mp(maxx.s, i);	
		}
		else if(maxx.f==ans){
			if(i-maxx.s<interval.s-interval.f){
				interval=mp(maxx.s, i);
			}
		}
	}
	
	if(ans<=0.00) cout<<"no profit\n";
	else {
		cout<<setprecision (2) << fixed <<ans<<" ";
		cout<<interval.f<<" "<<interval.s<<"\n";
	}
}

return 0;
}

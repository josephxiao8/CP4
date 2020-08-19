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


int t,n;
vector<pair<double,double> > v;

double time(double r){
	double minn=DBL_MAX;
	for(int i=0; i<n; i++){
		double a,b;
		tie(a,b)=v[i];
		double time=60*60*((r/a)+((t-r)/b));
		if(i<n-1) minn=min(minn,time);
		else return minn-time;
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

while(cin>>t){
	cin>>n;
	v.clear();
	v=vector<pair<double,double> >(n);
	for(int i=0; i<n; i++){
		double a,b;
		cin>>a>>b;
		v[i]=mp(a,b);
	}
	
	double low=0, high=double(t);
	while(fabs(high-low)>1e-9){
		double delta=(high-low)/3.0;
		double r1=low+delta;
		double r2=high-delta;
		(time(r1)<time(r2)) ? low=r1 : high=r2;
	}
	
	double ans=(low+high)/2.0;
	if(time(ans)<0) cout<<"The cheater cannot win.";
	else cout<<"The cheater can win by "<<int(round(time(ans)))<<" seconds with r = "<<fixed<<setprecision(2)<<ans<<"km and k = "<<t-ans<<"km.";
	cout<<endl;
}
		
return 0;
}

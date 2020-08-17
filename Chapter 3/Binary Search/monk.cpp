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


vpi ascend,descend;

double elevation(double t){
	double ans=0;
	for(int i=0; i<ascend.size(); i++){
		int x,y;
		tie(x,y)=ascend[i];
		if(t>=y){
			t-=y;
			ans+=x;
		}
		else{
			ans+=double(x)*(t/double(y));
			break;
		}
	}
	return ans;
}

double elevation2(double t){
	double ans=0;
	for(int i=0; i<descend.size(); i++){
		int x,y;
		tie(x,y)=descend[i];
		if(t>=y){
			t-=y;
			ans+=x;
		}
		else{
			ans+=double(x)*(t/double(y));
			break;
		}
	}
	return ans;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int a,d,h;
cin>>a>>d;

ascend=vpi(a);
int time=0;
for(int i=0; i<a; i++){
	int x,y;
	cin>>x>>y;
	ascend[i]=mp(x,y);
	h+=x;
	time+=y;
}

int time2=0;
descend=vpi(d);
for(int i=0; i<d; i++){
	int x,y;
	cin>>x>>y;
	descend[i]=mp(x,y);
	time2+=y;
}

double mid, low=0, high=min(time,time2);
while(fabs(high-low)>1e-6){
	mid=(low+high)/2.0;
	if(elevation2(mid)+elevation(mid)<h) low=mid;
	else high=mid;
}

cout<<fixed<<setprecision(6)<<mid;
return 0;
}

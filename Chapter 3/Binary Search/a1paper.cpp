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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n;
cin>>n;
vi v(n);
for(int i=1; i<n; i++) cin>>v[i];

long double ans=0;
ll need=2;
for(double i=1; i<=n; i++){
	if(i==n){
		cout<<"impossible";
		break;
	}
	if(need<=v[i]){
		ans+=(need/2)*pow(2.0,-(1+(2*i))/4);
		cout<<fixed<<setprecision(11)<<ans;
		break;
	}
	else{
		ans+=(need/2)*pow(2.0,-(1+(2*i))/4);
		need-=v[i];
		need*=2;
	}
}
	
return 0;
}

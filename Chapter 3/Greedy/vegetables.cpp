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
 
typedef priority_queue<pair<double,int> > pq;
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

double t;
int n;
cin>>t>>n;

double minn=DBL_MAX;
pq q;
for(int i=0; i<n; i++){
	double temp;
	cin>>temp;
	q.push(mp(temp,1));
	minn=min(minn,temp);
}

int ans=0;
while(floor(minn)/ceil(q.top().f)<t){
	double a;
	int b;
	tie(a,b)=q.top();
	q.pop();
	q.push(mp(a*b/(b+1),b+1));
	minn=min(minn,a*b/(b+1));
	ans++;
}

cout<<ans;
return 0;
}

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

int n,m,k;
cin>>n>>m>>k;

vector<double> plots(n);
for(int i=0; i<n; i++) cin>>plots[i];
sort(plots.begin(), plots.end());

vector<double> circles(m+k);
for(int i=0; i<m; i++) cin>>circles[i];
for(int i=m; i<m+k; i++) {
	double temp;
	cin>>temp;
	circles[i]=sqrt((temp*temp)/2);
}
sort(circles.begin(), circles.end());

int p=0, c=0, ans=0;
while(p<n && c<m+k){
	if(circles[c]<plots[p]){
		ans++;
		c++;
		p++;
	}
	else p++;
}

cout<<ans;
return 0;
}

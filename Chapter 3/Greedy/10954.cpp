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
	pqg q;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		q.push(temp);
	}
	
	int ans=0;
	while(q.size()!=1){
		int a=q.top(); q.pop();
		int b=q.top(); q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	cout<<ans<<endl;
}

return 0;
}

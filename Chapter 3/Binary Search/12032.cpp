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


bool possible(int k, vi v){
	for(int i=0; i<v.size()-1; i++){
		if(v[i+1]-v[i]>k) return false;
		else if(v[i+1]-v[i]==k) k--;
	}
	return true;
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int t, casenum=1;
cin>>t;
while(casenum<=t){
	int n;
	cin>>n;
	vi v(n+1);
	v[0]=0;
	for(int i=1; i<=n; i++) cin>>v[i];
	int maxx=v[n];
	int k=0;
	for(int b=maxx/2; b>=1; b/=2){
		while(k+b<=maxx && !possible(k+b,v)) k+=b;
	}
	
	cout<<"Case "<<casenum<<": "<<k+1<<endl;
	casenum++;	
}


return 0;
}

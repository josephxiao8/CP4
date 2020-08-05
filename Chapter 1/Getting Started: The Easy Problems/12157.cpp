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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);


int t, counter=1;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int cost1=0, cost2=0;
	for(int i=0; i<n; i++){
		int d;
		cin>>d;
		cost1+=((d/30)+1)*10;
		cost2+=((d/60)+1)*15;
	}
	cout<<"Case "<<counter<<": ";
	if(cost1==cost2) cout<<"Mile Juice ";
	else if(cost1<cost2) cout<<"Mile ";
	else cout<<"Juice ";
	cout<<min(cost1,cost2)<<endl;
	counter++;
}

return 0; 
}

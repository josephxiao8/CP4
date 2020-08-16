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

int n,h;
cin>>n>>h;
vi mites, tites;

for(int i=0; i<n; i++){
	int temp;
	cin>>temp;
	if(i%2==0) mites.pb(temp);
	else tites.pb(temp);
}
sort(mites.begin(), mites.end());
sort(tites.begin(), tites.end());

int minn=INT_MAX, numoflevels=0;
for(int i=1; i<=h; i++){
	int counter=0;
	counter+=mites.end()-lb(mites.begin(), mites.end(), i);
	counter+=tites.end()-lb(tites.begin(),tites.end(), h-i+1);
	if(counter<minn){
		minn=counter;
		numoflevels=1;
	}
	else if(counter==minn) numoflevels++;
}

cout<<minn<<" "<<numoflevels;
return 0;
}

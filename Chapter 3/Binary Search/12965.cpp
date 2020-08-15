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

int t;
cin>>t;
while(t--){
	int p,c;
	cin>>p>>c;
	vi producers(p);
	for(int i=0; i<p; i++) cin>>producers[i];
	sort(producers.begin(), producers.end());
	vi consumers(c);
	for(int i=0; i<c; i++) cin>>consumers[i];
	sort(consumers.begin(), consumers.end());
	
	int price=0, angry=producers.end()-ub(producers.begin(), producers.end(),0);
	for(auto it=producers.begin(); it!=producers.end(); it++){
		int tempprice, tempangry=0;
		tempprice=*it;
		tempangry+=producers.end()-it-1;
		tempangry+=lb(consumers.begin(), consumers.end(), *it)-consumers.begin();
		if(tempangry<angry){
			price=tempprice;
			angry=tempangry;
		}
	}
	cout<<price<<" "<<angry<<endl;
}

return 0;
}

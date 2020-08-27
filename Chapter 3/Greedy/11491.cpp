#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
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

int n,d;
while(cin>>n>>d, !(n==0 && d==0)){
	string num;
	cin>>num;
	string ans="";
	int pos=0, maxx=-1;
	while(pos+d<num.size()){
		int prevpos=pos;
		int id;
		for(int i=pos; i<=pos+d; i++){
			if(num[i]-'0'>maxx){
				id=i;
				maxx=num[i]-'0';
			}
		}
		ans+=num[id];
		pos=id+1;
		d-=id-prevpos;
		maxx=-1;
	}
	
	cout<<ans<<endl; 
}

return 0;	
}

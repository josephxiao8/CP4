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

ll n,t;
cin>>n>>t;

vl v(n);
for(ll i=0; i<n; i++) cin>>v[i];


if(t==1) cout<<7;

else if(t==2){
	if(v[0]==v[1]) cout<<"Equal";
	else cout<<((v[0]>v[1]) ? "Bigger":"Smaller");
}

else if(t==3){
	sort(v.begin(), v.begin()+3);
	cout<<v[1];
}

else if(t==4){
	ll sum=0;
	for(auto x:v) sum+=x;
	cout<<sum;
}

else if(t==5){
	ll sum=0;
	for(auto x:v) if(x%2==0) sum+=x;
	cout<<sum;
}

else if(t==6){
	for(int i=0; i<v.size(); i++) v[i]%=26;
	for(auto x:v) cout<<char(x+'a');
}
else if(t==7){
	set<ll> sett;
	ll temp=0;
	while(1){
		if(sett.count(temp)){
			cout<<"Cyclic";
			break;
		}
		
		else{
			sett.insert(temp);
			if(!(0<=temp && temp<=n-1)){
				cout<<"Out";
				break;
			}
			else if(temp==n-1){
				cout<<"Done";
				break;
			}
			else temp=v[temp];
		}
	}
}

return 0; 
}

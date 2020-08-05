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


while(1){
	int n;
	cin>>n;
	if(n==0) break;
	string ans="+x";
	
	for(int i=0; i<n-1; i++){
		string s;
		cin>>s;
		
		if(s=="No") continue;
		
		if(ans=="+x"){
			if(s=="+y") ans="+y";
			else if(s=="-y")ans="-y";
			else if(s=="+z")ans="+z";
			else ans="-z";
		}
		
		else if(ans=="-x"){
			if(s=="+y") ans="-y";
			else if(s=="-y")ans="+y";
			else if(s=="+z")ans="-z";
			else ans="+z";
		}
		
		else if(ans=="+y"){
			if(s=="+y") ans="-x";
			else if(s=="-y")ans="+x";
			else if(s=="+z")ans=ans;
			else ans=ans;
		}
		
		else if(ans=="-y"){
			if(s=="+y") ans="+x";
			else if(s=="-y")ans="-x";
			else if(s=="+z")ans=ans;
			else ans=ans;
		}
		
		else if(ans=="+z"){
			if(s=="+y") ans=ans;
			else if(s=="-y") ans=ans;
			else if(s=="+z") ans="-x";
			else ans="+x";
		}
		
		else if(ans=="-z"){
			if(s=="+y") ans=ans;
			else if(s=="-y") ans=ans;
			else if(s=="+z") ans="+x";
			else ans="-x";
		}
	}
	cout<<ans<<endl;
}
return 0; 
}

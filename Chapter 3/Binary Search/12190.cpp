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


vpi cost={{0,200},{203,29900},{29905,4979900}};
vpi range={{1,100}, {101,10000}, {10001,1000000}};
vi price={2, 3, 5, 7};

int pay(int k){
	int temp;
	for(int i=0; i<4; i++){
		if(i==3){
			temp=i;
			break;
		}
		
		int l,u;
		tie(l,u)=range[i];
		if(l<=k && k<=u){
			temp=i;
			break;
		}
	}
	
	int ans=0;
	if(temp-1>=0){
		ans+=cost[temp-1].s;
		ans+=(k-range[temp-1].s)*price[temp];
	}
	else ans+=k*price[temp];
	
	return ans;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int A,B;
while(cin>>A>>B && !(A==0 && B==0)){
	int temp;
	for(int i=0; i<4; i++){
		if(i==3){
			temp=i;
			break;
		}
		
		int l,u;
		tie(l,u)=cost[i];
		if(l<=A && A<=u){
			temp=i;
			break;
		}
	}
	
	int energy=0;
	if(temp-1>=0){
		energy+=range[temp-1].s;
		energy+=(A-cost[temp-1].s)/price[temp];
	}
	else energy+=A/price[temp];
	
	
	int k=0;
	for(int b=energy/4; b>=1; b/=2){
		while(k+b<=energy/2 && (pay(energy-(k+b))-pay(k+b))>=B) k+=b;
	}
	cout<<pay(k)<<endl;
}

return 0;
}

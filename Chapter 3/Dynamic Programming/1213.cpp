#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
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

vi primes;
for(int i=2; i<=1120; i++){
	for(int j=2; j<=i; j++){
		if(j==i) primes.pb(i);
		else if(i%j==0) break;
	}
}

int a,b;
while(cin>>a>>b && !(a==0 && b==0)){
	vector<vi> dp(a+1,vi(b+1,0)); //dp[i][j]=# of ways to make sum i with j numbers
	dp[0][0]=1;
	for(auto x:primes){ //using the first "n" prime numbers
		for(int j=b; j>=1; j--){
			for(int i=a; i>=1; i--){
				if(i-x>=0) dp[i][j]+=dp[i-x][j-1];	
			}
		}
	}
	int ans=dp[a][b];
	cout<<ans<<"\n";
}

return 0;
}






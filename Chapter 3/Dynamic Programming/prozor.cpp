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

int r,s,k;
cin>>r>>s>>k;

vector<vi> prefix(r+1,vi(s+1,0));
for(int j=1; j<=r; j++){
	for(int i=1; i<=s; i++){
		char c;
		cin>>c;
		int temp;
		if(c=='.') temp=0;
		else temp=1;
		prefix[j][i]=prefix[j][i-1]+prefix[j-1][i]-prefix[j-1][i-1]+temp;
	}
}

pi coord;
int ans=0;
for(int j=0; j<=r-k; j++){
	for(int i=0; i<=s-k; i++){
		int temp=prefix[j+k-1][i+k-1]-prefix[j+1][i+k-1]-prefix[j+k-1][i+1]+prefix[j+1][i+1];
		if(temp>ans){
			ans=temp;
			coord=mp(j,i);
		}
	}
}

cout<<ans<<endl;
for(int j=1; j<=r; j++){
	for(int i=1; i<=s; i++){
		bool b=false;
		if(j==coord.f+1 && (i>=coord.s+1 && i<=coord.s+k)) b=true;
		if(j==coord.f+k && (i>=coord.s+1 && i<=coord.s+k)) b=true;
		if(i==coord.s+1 && (j>=coord.f+1 && j<=coord.f+k)) b=true;
		if(i==coord.s+k && (j>=coord.f+1 && j<=coord.f+k)) b=true;
		if(b) {
			if(j==coord.f+1 && i==coord.s+1) cout<<'+';
			else if(j==coord.f+1 && i==coord.s+k) cout<<'+';
			else if(j==coord.f+k && i==coord.s+1) cout<<'+';
			else if(j==coord.f+k && i==coord.s+k) cout<<'+';
			else if(j==coord.f+1 || j==coord.f+k) cout<<'-';
			else cout<<'|';
			continue;
		}
		int temp=prefix[j][i]-prefix[j-1][i]-prefix[j][i-1]+prefix[j-1][i-1];
		if(temp==1) cout<<'*';
		else cout<<'.';
	}
	cout<<endl;
}

return 0;
}

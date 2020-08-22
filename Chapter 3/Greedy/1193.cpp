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
 
typedef priority_queue<tuple<int,int,int> > pq;
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

int n, casenum=1;
double d;
while(cin>>n>>d, !(n==0 && d==0)){
	vector<pair<double,double> > v(n);
	bool possible=true;
	for(int i=0; i<n; i++){
		double x,y;
		cin>>x>>y;
		if(y>d) possible=false;
		v[i]=mp(x-sqrt((d*d)-(y*y)),x+sqrt((d*d)-(y*y)));
	}
	
	if(!possible) cout<<"Case "<<casenum<<": "<<-1<<endl;
	else{
		sort(v.begin(), v.end());
		int ans=0;
		for(int i=0; i<v.size(); i++){
			double l,u;
			tie(l,u)=v[i];
			for(int j=i; j<v.size(); j++){
				double l_2, u_2;
				tie(l_2,u_2)=v[j];
				if(l<=l_2 && l_2<=u){
					l=l_2;
					u=min(u,u_2);
				}
				else{
					ans++;
					i=j-1;
					break;
				}
			}
		}
		cout<<"Case "<<casenum<<": "<<ans+1<<endl;
	}
	
	casenum++;
}

return 0;
}

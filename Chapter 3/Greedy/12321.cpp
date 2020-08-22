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


bool comp(pi a, pi b){
	if(a.f==b.f) return a.s>b.s;
	else return a.f<b.f;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int l,g;
while(cin>>l>>g, !(l==0 && g==0)){
	vpi v(g);
	for(int i=0; i<g; i++){
		int x,r;
		cin>>x>>r;
		v[i]=mp(x-r,x+r);
	}
	sort(v.begin(), v.end(), comp);
	
	int covered=0;
	int ans=0;
	bool possible=true;
	for(int i=0; i<g; i++){
		if(covered>=l) break;
		if(v[i].s<=covered) continue;
		if(v[i].f<=covered){
			int max_r=-1;
			int max_id;
			for(int j=i; j<g && v[j].f<=covered; j++){
				if(v[j].s>max_r){
					max_r=v[j].s;
					max_id=j;
				}
			}
			ans++;
			covered=max_r;
			i=max_id;
		}
		else{
			possible=false;
			break;
		}
	}
	
	if(!possible || covered<l) cout<<-1<<endl;
	else cout<<g-ans<<endl;
}

return 0;
}


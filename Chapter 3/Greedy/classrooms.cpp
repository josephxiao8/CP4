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
	return a.s<b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n,k;
cin>>n>>k;

vpi v(n);
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v[i]=mp(a,b);
}
sort(v.begin(), v.end(), comp);

multiset<int> sett;
for(int i=0; i<k; i++) sett.insert(0);

int ans=0;
for(int i=0; i<n; i++){
	auto it=sett.lb(v[i].f);
	if(it==sett.begin()) continue;
	else{
		sett.erase(--it);
		sett.insert(v[i].s);
		ans++;
	}
}

cout<<ans;
return 0;
}

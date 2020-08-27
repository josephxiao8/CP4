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

string s1,s2;
cin>>s1>>s2;

int pos=INT_MAX;
for(int i=0; i<s1.size() && i<s2.size(); i++){
	if(s1[i]!=s2[i]){
		pos=i;
		break;
	}
}

if(pos==INT_MAX){
	if(s1.size()>=s2.size()) cout<<0;
	else cout<<s2.size()-s1.size();
	return 0;
}

string ans=s2.substr(pos);
auto it1=(--s1.end());
auto it2=(--ans.end());
while(it1!=(--s1.begin()) && it2!=(--ans.begin()) && *it1==*it2){
	ans.pop_back();
	s1.pop_back();
	it1=(--s1.end());
	it2=(--ans.end());
}

cout<<int(ans.size());
return 0;	
}

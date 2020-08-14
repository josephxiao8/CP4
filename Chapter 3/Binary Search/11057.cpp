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

int n;
while(cin>>n){
	vi book(n);
	for(int i=0; i<n; i++) cin>>book[i];
	sort(book.begin(), book.end());
	int m;
	cin>>m;
	
	int l,r, dif=INT_MAX;
	for(int i=0; i<n-1; i++){
		int low=i+1, high=n-1;
		while(low<=high){
			int mid=(high+low)/2;
			if(book[mid]==m-book[i]){
				if(abs(book[i]-book[mid])<dif) l=i, r=mid, dif=abs(book[i]-book[mid]);
				break;
			}
			else (book[mid]<m-book[i]) ? (low=mid+1) : (high=mid-1);
		}
	}
	
	cout<<"Peter should buy books whose prices are "<<book[l]<<" and "<<book[r]<<"."<<endl<<endl;
}

return 0;
}

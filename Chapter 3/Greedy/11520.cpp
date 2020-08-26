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

int t, casenum=1;
cin>>t;
while(t--){
	int n;
	cin>>n;
	vector<vector<char> > grid(n, vector<char>(n));
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>grid[j][i];
		}
	}
	
	cout<<"Case "<<casenum++<<":"<<endl;
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(grid[j][i]=='.') {
				
				vi dy={1,-1,0,0};
				vi dx={0,0,1,-1};
				
				set<char> sett;
				for(int k=0; k<4; k++){
					int y=j+dy[k];
					int x=i+dx[k];
					if(0<=y && y<n && 0<=x && x<n) sett.insert(grid[y][x]);
				}
				
				for(int k=0; k<5; k++){
					if(sett.count(char(k+65))) continue;
					grid[j][i]=char(k+65);
					break;
				}
			}	
			cout<<grid[j][i];
		}
		cout<<endl;
	}
}

return 0;	
}

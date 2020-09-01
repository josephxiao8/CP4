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

int t;
cin>>t;
while(t--){
	int black=0, white=0;
	vector<vector<char> > grid(9, vector<char>(9));
	vector<vector<bool> > visited(9,vector<bool>(9,false));
	for(int j=0; j<9; j++){
		for(int i=0; i<9; i++){
			char temp;
			cin>>temp;
			grid[j][i]=temp;
			if(temp=='O') white++;
			else if(temp=='X') black++;
		}
	}
	
	for(int j=0; j<9; j++){
		for(int i=0; i<9; i++){
			if(!visited[j][i] && grid[j][i]=='.'){
				visited[j][i]=true;
				queue<pi> q;
				q.push(mp(j,i));
				set<char> sett;
				int counter=1;
				vi dy={1,-1,0,0};
				vi dx={0,0,1,-1};
				while(!q.empty()){
					int a,b;
					tie(b,a)=q.front(); q.pop();
					for(int k=0; k<4; k++){
						int c=a+dx[k];
						int d=b+dy[k];
						if(c<0|| c>=9 || d<0 || d>=9) continue;
						if(!visited[d][c] && grid[d][c]=='.'){
							counter++;
							visited[d][c]=true;
							q.push(mp(d,c));
						}
						else if(grid[d][c]!='.') sett.insert(grid[d][c]);
					}
				}
				if(sett.size()==1){
					if(*(sett.begin())=='O') white+=counter;
					else black+=counter;
				}
			}
		}
	}
	cout<<"Black "<<black<<" White "<<white<<endl;
}

return 0;	
}

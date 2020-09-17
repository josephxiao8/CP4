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

int y,x,z;
while(cin>>y>>x>>z && !(y==0 && x==0 && z==0)){
	z--;
	vector<vector<char> > grid(y, vector<char>(x));
	for(int j=0; j<y; j++){
		for(int i=0; i<x; i++){
			cin>>grid[j][i];
		}
	}
	
	map<char,int> mapp;
	mapp['N']=0;
	mapp['E']=1;
	mapp['S']=2;
	mapp['W']=3;
	
	vi dy={-1,0,1,0};
	vi dx={0,1,0,-1};
	
	vector<vi> visited(y,vi(x,-1));
	queue<pair<pi,int> > q;
	q.push(mp(mp(0,z),1));
	visited[0][z]=1;
	
	while(!q.empty()){
		int a,b,steps;
		tie(b,a)=q.front().f;
		steps=q.front().s;
		q.pop();
		
		int c=a+dx[mapp[grid[b][a]]];
		int d=b+dy[mapp[grid[b][a]]];
		
		if(c<0 || c>=x || d<0 || d>=y){
			cout<<steps<<" step(s) to exit"<<endl;
			break;
		}
		if(visited[d][c]!=-1){
			cout<<visited[d][c]-1<<" step(s) before a loop of "<<steps+1-visited[d][c]<<" step(s)"<<endl;
			break;
		}
		
		visited[d][c]=steps+1;
		q.push(mp(mp(d,c),steps+1));
	}
}

return 0;
}

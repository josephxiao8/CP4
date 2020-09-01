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

int r,c;
cin>>r>>c;
vector<vector<char> > grid(r, vector<char>(c));
for(int j=0; j<r; j++){
	string temp;
	cin>>temp;
	for(int i=0; i<c; i++){
		grid[j][i]=temp[i];
	}
}

vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
vector<vector<bool> > visited(r, vector<bool>(c,false));
vector<vi> state(r, vi(c));
int num=1;
for(int j=0; j<r; j++){
	for(int i=0; i<c; i++){
		if(!visited[j][i]){
			visited[j][i]=true;
			state[j][i]=num;
			queue<pi> q;
			q.push(mp(j,i));
			while(!q.empty()){
				int a,b;
				tie(b,a)=q.front(); q.pop();
				for(int k=0; k<4; k++){
					int e=a+dx[k];
					int f=b+dy[k];
					if(e<0 || e>=c || f<0 || f>=r) continue;
					if(grid[f][e]==grid[j][i] && !visited[f][e]){
						visited[f][e]=true;
						state[f][e]=num;
						q.push(mp(f,e));
					}
				}		
			}
			num++;
		}
	}
}

int n;
cin>>n;
for(int i=0; i<n; i++){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a--;
	b--;
	c--;
	d--;
	if(state[a][b]==state[c][d]){
		if(grid[a][b]=='1') cout<<"decimal"<<endl;
		else cout<<"binary"<<endl;
	}
	else cout<<"neither"<<endl;
}

return 0;	
}

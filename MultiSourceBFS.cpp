/* ques: Snakes and transition from Capitalism to Socialism
After a long duration of the painful, torturous and tumultuous periods of capitalism in Snakeland, now the snakes have decided to adopt socialism. 
The houses in Snakeland are arranged in a rectangular fashion of dimension n * m. The wealth of the snake in the house at cell (i, j) is given by a[i][j] rupees.
A bill has been passed for making a smooth transition from capitalism to socialism. At the end of each hour, the wealth of a snake will grow and will become equal
to the highest wealth that its neighbor had (at the start of the hour). That is, consider the maximum wealth among its neighbors at the start of the hour, and this
snake's wealth will become equal to that at the end of the hour. Note that this increase in wealth will happen simultaneously for each snake. Two houses are said to
be neighbors of each other if they share a side or corner with each other. Find out the minimum number of hours required for this transition.
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space separated integers: n, m.
Each of the next n lines contains m space separated integers. The j-th integer in the i-th row denotes a[i][j].
Output
For each test case output a single integer corresponding to the minimum number of hours required for the transition.
Constraints
1 ≤ T ≤ 4
1 ≤ n, m ≤ 500
1 ≤ a[i][j] ≤ 106
Example
Input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
Output
0
1
2
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;
int val[N][N];
int vis[N][N];
int lev[N][N];
int n,m;
vector<pair<int,int>> movements={
	{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}
};
bool isValid(int x,int y){
	return x>=0 && y>=0 && x<n && y<m;
}
int bfs(){
    int mx=0;
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mx=max(mx,val[i][j]);
		}
	}
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mx==val[i][j]){
			    q.push({i,j});
			    lev[i][j]=0;
			    vis[i][j]=1;
			}
		}
	}
	int ans=0;
	while(!q.empty()){
		auto v = q.front();
		int v_x=v.first;int v_y=v.second;
		q.pop();
		for(auto movement : movements){
			int childX = movement.first+v_x;
			int childY = movement.second+v_y;
			if(!isValid(childX,childY)) continue;
			if(!vis[childX][childY]) continue;
				q.push({childX,childY});
				lev[childX][childY] = lev[v_x][v_y]+1;
				vis[childX][childY]=1;
				ans=max(ans,lev[childX][childY]);
			
		}
	}
	return ans;
}
void reset(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			lev[i][j]=INF;
			vis[i][j]=0;
		}
	}
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        reset();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
}

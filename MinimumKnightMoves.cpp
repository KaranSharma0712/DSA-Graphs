#include <bits/stdc++.h>
using namespace std;
const int N =1e5+10;
const int INF = 1e9+10;
int vis[8][8];
int level[8][8];


int getX(string s){
	return s[0]-'a';
}
int getY(string s){
	return s[1]-'1';
}
bool isValid(int x,int y){
	return x>=0 && y>=0 && x<8 && y<8;
}
vector<pair<int,int>> movements={
	{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}
};
int bfs(string src,string des){
	int srcX=getX(src);
	int srcY=getY(src);
	int desX=getX(des);
	int desY=getY(des);
	queue<pair<int,int>> q;
	q.push({srcX,srcY});
	vis[srcX][srcY]=1;
	level[srcX][srcY]=0;
	
	while(!q.empty()){
		pair<int,int> v = q.front();
		int x=v.first;int y=v.second;
		q.pop();
		for(auto movement : movements){
			int childX = movement.first+x;
			int childY = movement.second+y;
			if(!isValid(childX,childY)) continue;
			if(!vis[childX][childY]){
				q.push({childX,childY});
				level[childX][childY] = level[x][y]+1;
				vis[childX][childY]=1;
			}
		}
		if(level[desX][desY]!=INF){
			break;
		}
		
	}
	return level[desX][desY];
}
void reset(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			level[i][j]=INF;
			vis[i][j]=0;
		}
	}
}
int main() {
	
	int n;
	cin>>n;
	while(n--){
	    reset();
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
	}

	
}

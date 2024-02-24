#include<bits/stdc++.h>
using namespace std;
const int N=10e5;
bool visited[N]={0};
vector<int> graph[N];

bool dfs(int v,int par){
    visited[v]=true;
    bool isLoopExists = false;
    for(int child:graph[v]){
        if(visited[child] && child==par) continue;
        if(visited[child]) return true;
        isLoopExists |= dfs(child,v);
    } 
    return isLoopExists; 
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    int count=0;
    bool isLoopExists=false;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        
        if(dfs(i,0)){
            isLoopExists=true;
            break;
        }
        
        count++;
    }
    cout<<isLoopExists<<endl;
    
    
}

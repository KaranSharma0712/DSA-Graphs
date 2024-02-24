#include<bits/stdc++.h>
using namespace std;
const int N=10e5;
bool visited[N]={0};
vector<int> graph[N];
void dfs(int v){
    visited[v]=true;
    for(int child:graph[v]){
        if(visited[child]) continue;
        dfs(child);
    }
    
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
    for(int i=1;i<=n;i++){
        if(visited[i]){
            continue;
        };
        dfs(i);
        count++;
    }
    cout<<count<<endl;
}

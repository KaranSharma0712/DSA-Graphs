#include<bits/stdc++.h>
using namespace std;
const int N=10e5;
bool visited[N]={0};
vector<int> graph[N];
vector<vector<int>> cc;
vector<int> current_cc;
void dfs(int v){
    visited[v]=true;
    current_cc.push_back(v);
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
        if(visited[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        count++;
    }
    cout<<count<<endl;
    for(auto c_cc:cc){
        for(int vertex : c_cc){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
}

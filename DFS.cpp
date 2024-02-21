#include <bits/stdc++.h>
using namespace std;
const int N=10e5;
bool vis[N]={0};
vector<int> graph[N];

void makelink(int v1,int v2){
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void dfs(int v){
    cout<<v<<endl;
    vis[v]=true;
    for(int child:graph[v]){
        cout<<"par "<<v<<" child "<<child<<endl;
        if(vis[child]) continue;
        dfs(child);
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    while(e--){
        int s,d;
        cin>>s>>d;
        makelink(s,d);
    }
    cout<<endl;
    dfs(v);

    return 0;
}

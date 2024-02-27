#include <bits/stdc++.h>
using namespace std;
const int N = 10e5+10;
int par[N];
vector<int> g[N];
int subtree_sum[N];
int even_count[N];
void dfs(int v,int p=-1){
    par[v]=p;
    for(int child : g[v]){
        if(child==p) continue;
        dfs(child,v);
        subtree_sum[v]+=subtree_sum[child];
        even_count[v]+=even_count[child];
    }
    subtree_sum[v]+=v;
    if(v%2==0) even_count[v]++;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<" "<<even_count[i]<<endl;
    }
}

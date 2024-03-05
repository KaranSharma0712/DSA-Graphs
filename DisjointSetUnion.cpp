#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int par[N];
int sizee[N];
void make(int v){
    par[v]=v;
    sizee[v]=1;
}
int find(int v){
    if(v==par[v]) return v;
    return par[v]=find(par[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sizee[a]<sizee[b]) swap(a,b);
        par[b]=a;
        sizee[a]+=sizee[b];
    }
}
int main() {
    //finding number of connected components
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_ct=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) connected_ct++;
    }
    cout<<connected_ct<<endl;
}

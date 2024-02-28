const int N = 1e9+7;
void dfs(int v,int p,vector<int> g[],vector<int> &subtree_sum,vector<int> &val){
    
    for(int child : g[v]){
        if(child==p) continue;
        dfs(child,v,g,subtree_sum,val);
        subtree_sum[v]+=subtree_sum[child];
        
    }
    subtree_sum[v]+=val[v-1];
    
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> g[A.size()+1];
    vector<int> subtree_sum(A.size()+1,0);
    for(auto edge : B){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }
    dfs(1,0,g,subtree_sum,A);
    long long ans=0;
    for(int i=2;i<=A.size();i++){
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(ans,(part1* 1LL * part2));
    }
    return ans;
}

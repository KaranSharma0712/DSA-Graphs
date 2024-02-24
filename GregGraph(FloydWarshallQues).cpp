/* ques: Greg has a weighed directed graph, consisting of n vertices. In this graph any pair of distinct vertices has an edge between them in both
directions. Greg loves playing with the graph and now he has invented a new game:
• The game consists of n steps.
• On the i-th step Greg removes vertex number Xi from the graph. As Greg removes a vertex, he also removes all the edges that go in
and out of this vertex.
• Before executing each Step, Greg wants to know the sum Of lengths Of the shortest paths between all pairs Of the remaining vertices.
The shortest path can go through any remaining vertex. In other words, if we assume that d(i, v, u) is the shortest path between
vertices v and u in the graph that formed before deleting vertex Xi, then Greg wants to know the value of the following sum:
Help Greg, print the value of the required sum before each step. 
Input
The first line contains integer n (1 ≤ n ≤ 500) — the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: the j-th number in the i-th line aij (1 ≤ aij ≤ 105, aii = 0) represents the weight of the edge that goes from vertex i to vertex j.
The next line contains n distinct integers: x1, x2, ..., xn (1 ≤ xi ≤ n) — the vertices that Greg deletes.
Output
Print n integers — the i-th number equals the required sum before the i-th step.
Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

code:*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;

long long int dist[N][N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    vector<int> del_order(n);
    for(int i=0;i<n;i++){
        cin>>del_order[i];
    }
    vector<long long > ans;
    reverse(del_order.begin(),del_order.end());
    for(int k=0;k<n;k++){
        int k_v=del_order[k];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k_v]+dist[k_v][j]);
            }
        }
        long long sum=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                sum+= dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto val: ans){
        cout<<val<<endl;
    }
}

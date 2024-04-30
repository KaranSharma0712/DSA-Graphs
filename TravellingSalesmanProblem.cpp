#include<bits/stdc++.h>
using namespace std;
int travellingSalesmanProblem(int **graph,int s,int n){
    vector<int> vertex;
    for(int i=0;i<n;i++){
        if(i!=s){
            vertex.push_back(i);
        }
    }
    int min_path = INT_MAX;
    do{
        int current_pathweight = 0;
        int k = s;
        for(int i=0 ; i < vertex.size();i++){
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path,current_pathweight);
    }
    while(next_permutation(vertex.begin(),vertex.end()));
    
    return min_path;
}

int main(){
    int n;
    cin >> n;
    int **graph = new int *[n];
    for(int i=0; i<n; i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>> graph[i][j];
        }
    }
    int s = 0;
    cout<<"Total cost of TSP: "<<travellingSalesmanProblem(graph,s,n)<<endl;
    for(int i=0 ; i<n ; i++){
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}

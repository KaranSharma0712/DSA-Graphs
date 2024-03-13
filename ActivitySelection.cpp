#include<bits/stdc++.h>
using namespace std;

void activitySelection(int s[],int f[],int n){
    vector<pair<pair<int,int>,int>> act;
    for(int i=0;i<n;i++){
        act.push_back({{s[i],f[i]},i});
    }
    sort(act.begin(),act.end(),[](const auto& a, const auto& b){
        return a.first.second < b.first.second;
    });
    int i,j;
    i = 0;
    cout<<act[i].second << " ";
    for(int j = 1; j < n; j++){
        if (act[j].first.first>=act[i].first.second){
            cout<<act[j].second<<" ";
            i = j;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int s[n];
    int f[n];
    for(int i = 0; i < n ; i++){
        cin >> s[i]; 
    }
    for(int i = 0; i < n ; i++){
        cin >> f[i];
    }
    activitySelection(s,f,n);
}

#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> activitySelection(int s[],int f[],int n){
    vector<pair<pair<int,int>,int>> act;
    for(int i=0;i<n;i++){
        act.push_back({{s[i],f[i]},i});
    }
    sort(act.begin(),act.end(),[](const auto& a, const auto& b){
        return a.first.second < b.first.second;
    });
    vector<pair<pair<int, int>, int>> selectedActivities;
    int i,j;
    i = 0;
    
    selectedActivities.push_back(act[i]);
    for(int j = 1; j < n; j++){
        if (act[j].first.first>=act[i].first.second){
            selectedActivities.push_back(act[j]);
            i = j;
        }
    }
    return selectedActivities;
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
    vector<pair<pair<int,int>,int>> result = activitySelection(s,f,n);
    for(const auto &activity : result){
        cout << activity.first.first << " " << activity.first.second<<endl;
    }
}

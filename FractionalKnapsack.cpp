#include<bits/stdc++.h>
using namespace std;
struct Item{
    int weight;
    int value;
    double ratio;
};
void fractionalKnapsack(int n, vector<int> weight,vector<int> value,int capacity){
    vector<Item> items(n);
    for(int i=0;i<n;i++){
        items[i].weight = weight[i];
        items[i].value = value[i];
        items[i].ratio = static_cast<double>(value[i])/weight[i];
    }
    sort(items.begin(),items.end(),[](const Item &a,const Item &b){
       return a.ratio > b.ratio; 
    });
    double totalProfit = 0.0;
    for(const Item &item : items){
        if(capacity >= item.weight){
            cout<<item.weight<<" "<<item.value<<endl;
            totalProfit += item.value;
            capacity -= item.weight;
            
        }
        else{
            double fraction = static_cast<double>(capacity)/item.weight;
            if(fraction > 0.0){
                cout << capacity << " " << fixed<<setprecision(3)<<item.value*fraction <<endl;
                totalProfit += item.value*fraction;
            }
            break;
        }
    }
    if (totalProfit == static_cast<int>(totalProfit)){
        cout<<"Total Profit: "<<fixed<<setprecision(0)<<totalProfit<<endl;
    }
    else{
        cout<<"Total Profit: "<<fixed<<setprecision(3)<<totalProfit<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int capacity;
    cin>>capacity;
    fractionalKnapsack(n,weight,value,capacity);
    
}

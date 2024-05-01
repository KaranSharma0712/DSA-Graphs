#include<iostream>
#include<vector>
using namespace std;

void SubsetSum(int arr[],int targetSum,int currentSum,int startIndex,int size,bool &found,int currentSubset[],int currentSize){
    
    if(targetSum == currentSum)
        found = true;
    for(int i = startIndex; i < size; i++){
        if(currentSum + arr[i] <= targetSum){
            currentSubset[currentSize++] = arr[i];
            currentSum += arr[i];
            SubsetSum(arr,targetSum,currentSum,i+1,size,found,currentSubset,currentSize);
            currentSubset[currentSize--] = arr[i];
            currentSum -= arr[i];
        }
    }
    for(int i =0;i<currentSize;i++){
        cout<< currentSubset[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int n,targetSum;
    bool found = false;
    cin>>n;
    int *arr = new int[n];
    int *currentSubset = new int[n];
    for(int i=0;i < n;i++){
        cin>>arr[i];
    }
    cin >> targetSum;
    SubsetSum(arr,targetSum,0,0,n,found,currentSubset,0);
    if (found)
        cout << "Subset with the given sum found: " << s << endl;
    else
        cout << "No required subset found" << endl;
    return 0;
}

bool canPlaceCows(vector<int>&stalls,int minDist, int cows){
    int cowCount  = cows; int lastPos = -1; 
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPos>=minDist || lastPos == -1){
            cowCount--;
            lastPos = stalls[i];
        }
        if(cowCount==0) break;
    }
    return cowCount==0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int low=0;
    int n = stalls.size();
    int high = stalls[n-1]-stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canPlaceCows(stalls,mid,k)==true){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

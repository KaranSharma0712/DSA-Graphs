class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        
        int max = 0;
        int n = arr.size();
        
        int ans = arr[0];
        for(int i=1;i<n;i++){
            ans = ans ^ arr[i];
        }
        if (ans == 0 || n==1){
            return -1;
        }
        
        for (int i=0; i<n; i++){
            if (arr[i] > max){
                max = arr[i];
            }
        }
        int temp = 0;
        for(int j = 0; j<n; j++){
            if (arr[j] < max && arr[j] > temp){
                temp = arr[j];
            }
        }
        return temp;
        
        
    }
};

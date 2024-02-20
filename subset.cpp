class Solution {
public:
    vector<vector<int>> finalsubsets;
    void generate(vector<int> &subset,int i,vector<int> nums){
        if(i==nums.size()){
            finalsubsets.push_back(subset);
            return;
        }
        //not taking ith element
        generate(subset,i+1,nums);

        //taking ith element
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        generate(empty,0,nums);
        return finalsubsets;
    }
};

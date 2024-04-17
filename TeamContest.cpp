/*Problem statement
School is organizing a team contest. You are given an array ‘SKILL’ containing the skill level of ‘N’ candidates.
Two candidates(having index ‘i’ and ‘j’) can pair up to form a team if for index i < j, SKILL[i] > 2*SKILL[j].
Your task is the return the count of all the possible pairs to take part in the contest.
Example:
Input: ‘N’ = 5
‘SKILL’ = [4, 1, 2, 3, 1] 
Output: 3
Explanation:
Possible pairs are (4,1), (4,1), (3,1).*/
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int>&arr,int low,int mid,int high){
    int right = mid+1;
    int count=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]){
            right++;
        }
        count+=(right-(mid+1));
    }
    return count;
}
int mergeSort(vector<int> &arr, int low, int high) {
    int count=0;
    if (low >= high) return count;
    int mid = (low + high) / 2 ;
    count += mergeSort(arr, low, mid);  // left half
    count += mergeSort(arr, mid + 1, high); // right half
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  // merging sorted halves
    return count;
}
int team(vector <int> & skill, int n)
{
   return mergeSort(skill, 0, n-1);
}

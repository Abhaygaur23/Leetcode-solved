class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
       vector<int> arr;
       int left = low;
       int right = mid+1;
       while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            arr.push_back(nums[left++]);
        }else{
            arr.push_back(nums[right++]);
        }
       }
       if(left<=mid){
        while(left<=mid){
            arr.push_back(nums[left++]);
        }
       }else{
        while(right<=high){
            arr.push_back(nums[right++]);
        }
       }
       for (int i = low; i <= high; i++) {
        nums[i] = arr[i - low];
       }
    }
    void mergesort(vector<int>& nums, int low, int high){
        if(low>=high){
            return;
        }
        int mid = low + (high-low)/2;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
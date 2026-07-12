class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = nums.size();
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                index = mid;
                break;
            }else if(nums[mid]>target){
                index = mid;
                end = mid-1;
            }else{
                start= mid+1;
            }
        }
        return index;
    }
};
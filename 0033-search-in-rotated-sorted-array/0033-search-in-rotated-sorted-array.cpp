class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0, end = nums.size()-1;
        while(start <= end ){
            int mid = start + (end - start)/2;
            if(nums[mid]==target){
                ans = mid;
                return ans;
            }else if(nums[mid]>=nums[0]){
                if(target>=nums[start] && target<=nums[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                 if(target<=nums[end] && target>=nums[mid]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return ans;
    }
};
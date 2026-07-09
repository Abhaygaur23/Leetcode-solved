class Solution {
public:
    void firstocc(vector<int>& nums, int target, int start, int end, int& first){
        if(start>end){
            return;
        }

            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                first = mid;
                firstocc(nums, target, start, mid-1, first);
            }else if(nums[mid]<target){
                firstocc(nums, target, mid+1, end, first);
            }else{
                firstocc(nums, target, start, mid-1, first);
            }

    }
    void lastocc(vector<int>& nums, int target, int start, int end, int& last){
        if(start>end){
            return;
        }

            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                last = mid;
                lastocc(nums, target, mid+1, end, last);
            }else if(nums[mid]<target){
                lastocc(nums, target, mid+1, end, last);
            }else{
                lastocc(nums, target, start, mid-1, last);
            }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last =  -1;
        firstocc(nums, target, 0, nums.size()-1, first);
        lastocc(nums, target, 0, nums.size()-1, last);
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
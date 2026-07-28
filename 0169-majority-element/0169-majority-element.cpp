class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(count==0){
                count++;
                cand = nums[i];
            }else if(nums[i]==cand){
                count++;
            }else{
                count--;
            }
        }
        return cand;
    }
};
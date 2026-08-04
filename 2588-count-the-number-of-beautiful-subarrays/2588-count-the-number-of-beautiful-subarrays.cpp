class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int xr = 0;
        map<int,int> m;
        m[xr]++;
        long long cnt = 0;
        for(int i=0; i<nums.size();i++){
            xr = xr^nums[i];
            int x = xr^0;
            cnt += m[x];
            m[xr]++;
        }
        return cnt;
    }
};
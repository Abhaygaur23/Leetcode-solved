class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sumn = n*(n+1)/2;
        // int sum = 0;
        // for(int i = 0; i<n; i++){
        //     sum += nums[i];
        // }
        // return sumn - sum;

        int n = nums.size();

        int XOR1 = 0, XOR2 = 0;

        for (int i = 0; i < n; i++) {
            XOR2 ^= nums[i];
            XOR1 ^= i;
        }

        XOR1 ^= n;

        return XOR1 ^ XOR2;
    }
};
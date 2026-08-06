class Solution {
public:
    int possible(vector<int>& nums, int mid) {
        int ans = 0;
        for (int x : nums) {
            ans += (x + mid - 1) / mid;   // ceil(x / mid)
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;   // search for a smaller valid divisor
            } else {
                low = mid + 1;    // divisor too small
            }
        }

        return ans;
    }
};
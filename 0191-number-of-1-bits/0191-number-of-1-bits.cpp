class Solution {
public:
    int hammingWeight(int n) {
        string ans = "";

        while (n > 0) {
            ans += (n % 2) + '0';
            n /= 2;
        }

        int cnt = 0;

        for (char c : ans) {
            if (c == '1')
                cnt++;
        }

        return cnt;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> lower(26, 0), upper(26, 0);
        int count = 0;
        bool odd = false;

        for (char c : s) {
            if (islower(c))
                lower[c - 'a']++;
            else
                upper[c - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0)
                count += lower[i];
            else {
                count += lower[i] - 1;
                odd = true;
            }

            if (upper[i] % 2 == 0)
                count += upper[i];
            else {
                count += upper[i] - 1;
                odd = true;
            }
        }

        if (odd)
            count++;

        return count;
    }
};

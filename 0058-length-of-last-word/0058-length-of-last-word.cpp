class Solution {
public:
    int lengthOfLastWord(string s) {
        long long i = s.size()-1;
        long long ans= 0;
        while(i>=0 && s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};
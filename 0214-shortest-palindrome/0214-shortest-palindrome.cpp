class Solution {
public:
    string shortestPalindrome(string s) {
        // code here
        string str = s;
        string rev = s; 
        reverse(rev.begin(), rev.end());
        int n = s.size();
        s+='$';
        s+=rev;
        vector<int> lps(s.size(),0);
        int first = 0, second = 1;
        while(second<lps.size()){
            if(s[first]==s[second]){
                lps[second] = first+1;
                second++;
                first++;
            }else{
                if(first==0){
                    second++;
                }else{
                    first = lps[first-1];
                }
            }
        }
        int x = lps[lps.size()-1];
        string u;
        for(int i = n-1; i>=x; i--){
            u+=str[i];
        }
        u+=str;
        return u;
    }
};
class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        for(int i = 0; i<=n-m; i++){
            int first = i, second = 0;
            while(second<m){
                if(s1[first]!=s2[second]){
                    break;
                }else{
                    first++;
                    second++;
                }
            }
            if(second==m){
                return first-second;
            }
        }
        return -1;
    }
};
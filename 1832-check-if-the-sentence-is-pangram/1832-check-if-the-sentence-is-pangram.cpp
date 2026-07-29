class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ans(26,0);
        int n = sentence.size();
        for(int i = 0; i<n; i++){
            int x  = sentence[i] - 'a';
            ans[x]++;
        }
        
        for(int i = 0; i<26; i++){
            if(ans[i]==0){
                return 0;
            }
        }
        return 1;
    }
};
class Solution {
public:
    string find(string str, string &s){
        int i=0;
        while(i < str.size() && i < s.size() && str[i] == s[i]){
                i++;
        }
        while(s.size()>i){
            s.pop_back();
        }
        return s;
    }
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        string s = str[0];
        for(int i = 1; i<n; i++){
            find(str[i], s);
            if(s.empty()) break;
        }
        return s;
    }
};
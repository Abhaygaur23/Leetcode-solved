class Solution {
public:
    void acw(string &str2){
        int n = str2.size();
        char c = str2[0];
        for(int i = 0; i<n-1; i++){
            str2[i]= str2[i+1];
        }
        str2[n-1] = c;
    }
    bool rotateString(string s, string goal) {
        string str2 = s;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(str2 == goal){
                return true;
            }else{
                acw(str2);
            }
        }
        return false;
    }
};
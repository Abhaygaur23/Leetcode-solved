class Solution {
public:
    string sortSentence(string s) {
        string temp = "";
        vector<string> str(10);
        for(char c: s){
           if(c==' '){
              int pos = temp[temp.size()-1] -'0';
              temp.pop_back();
              str[pos] = temp;
              temp = "";
           }else{
              temp += c;
           }
        }

        int pos = temp.back() - '0';
        temp.pop_back();
        str[pos] = temp;
        string ret = "";

        for(int i = 1; i<10; i++){
            if (!str[i].empty()) {
            ret += str[i];
            ret += ' ';
            }
        }
        ret.pop_back();
        return ret;
    }
};
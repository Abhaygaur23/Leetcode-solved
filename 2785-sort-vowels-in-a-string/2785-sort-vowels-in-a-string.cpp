class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26,0);
        vector<int> upper(26,0);
        for(int i= 0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                lower[s[i]-'a']++;
                s[i] = '#';
            }
        }
        for(int i= 0; i<s.size(); i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                upper[s[i]-'A']++;
                s[i] = '#';
            }
        }
        string str;
        for(int i= 0; i<26; i++){
            
            while(upper[i]){
               char c = i + 'A';
               str += c;
               upper[i]--;
            }
        }
        for(int i= 0; i<26; i++){
            
            while(lower[i]){
               char c = i + 'a';
               str += c;
               lower[i]--;
            }
        }
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#')
                s[i] = str[idx++];
        }
        return s;
    }
};
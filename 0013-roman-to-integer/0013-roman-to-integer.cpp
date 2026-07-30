class Solution {
public:
    int number(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c =='C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }
    int romanToInt(string num) {
       int n = num.size();
        int sum = 0;
        for(int i = 0; i<n-1; i++){
           if(number(num[i])<number(num[i+1])){
              sum -= number(num[i]);
           }else{
              sum += number(num[i]);
           }
        }
        sum+=number(num[num.size()-1]);
        return sum; 
    }
};
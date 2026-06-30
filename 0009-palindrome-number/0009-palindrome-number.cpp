class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        long long y = 0;
        long long n = x;
        while(n){
           long long carry = n % 10;
           y = y*10 + carry;
           n = n/10;
        }
        if(y==x){
            return true;
        } 
        else{
            return false;
        }
    }
};
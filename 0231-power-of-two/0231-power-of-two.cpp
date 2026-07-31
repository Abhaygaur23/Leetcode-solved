class Solution {
public:
    bool power(int n, long long ans){
        if(ans==n) return true;
        if(ans>n) return false;

        return power(n,ans*2);

    }
    bool isPowerOfTwo(int n) {
        long long ans = 1;
        if(n<=0) return false;
        return power(n,ans);
    }
};
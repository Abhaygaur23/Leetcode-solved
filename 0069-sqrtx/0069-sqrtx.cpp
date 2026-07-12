class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        long long start = 1, end = x;
        while(start<=end){
            long long mid = start + (end-start)/2;
            long long sq = mid*mid;
            if(sq==x){
               ans = mid;
               break;
            }else if(sq < x){
                 ans = mid;
                 start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};
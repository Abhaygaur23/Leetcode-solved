class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        if(k>arr.size()){
            return -1;
        }
        long long  end = 0;
        int start = 0;
        for(long long i = 0; i< arr.size(); i++){
            end += arr[i];
            start = max(start, arr[i]);
        }
        long long mid, ans;
        while(start<= end){
            mid = start + (end - start)/2;
            int pages= 0, count = 1;
            for(int i = 0; i< arr.size(); i++){
                pages+=arr[i];
                if(pages>mid){
                    count++;
                    pages = arr[i];
                }
            }
            if(count<=k){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};
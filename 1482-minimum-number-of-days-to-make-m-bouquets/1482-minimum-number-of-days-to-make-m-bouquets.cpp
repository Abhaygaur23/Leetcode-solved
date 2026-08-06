class Solution {
public:
    bool possible(vector<int>& arr,int mid, int m, int k){
        int cnt = 0;
        int no = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i]<=mid){
                cnt++;
            }else{
                no += (cnt/k);
                cnt = 0;
            }
        }
        no += (cnt/k);
        return no>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if((1ll)*m*(1ll)*k>n) return -1;
        int ans;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }
        while(mini<=maxi){
            int mid = mini + (maxi - mini)/2;
            if(possible(arr,mid,m,k)){
                ans = mid;
                 maxi = mid -1;
            }else{
                 mini = mid + 1;
            }
        }
        return ans;
    }
};
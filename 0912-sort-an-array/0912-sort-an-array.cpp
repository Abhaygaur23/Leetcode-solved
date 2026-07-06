class Solution {
public:
    // void merge(vector<int>& nums, int low, int mid, int high){
    //    vector<int> arr;
    //    int left = low;
    //    int right = mid+1;
    //    while(left<=mid && right<=high){
    //     if(nums[left]<=nums[right]){
    //         arr.push_back(nums[left++]);
    //     }else{
    //         arr.push_back(nums[right++]);
    //     }
    //    }
    //    if(left<=mid){
    //     while(left<=mid){
    //         arr.push_back(nums[left++]);
    //     }
    //    }else{
    //     while(right<=high){
    //         arr.push_back(nums[right++]);
    //     }
    //    }
    //    for (int i = low; i <= high; i++) {
    //     nums[i] = arr[i - low];
    //    }
    // }
    // void mergesort(vector<int>& nums, int low, int high){
    //     if(low>=high){
    //         return;
    //     }
    //     int mid = low + (high-low)/2;
    //     mergesort(nums, low, mid);
    //     mergesort(nums, mid+1, high);
    //     merge(nums, low, mid, high);
    // }
    int f(vector<int>& nums,int low, int high){
        // int pivot = nums[low]; for first as pivot but if222... TLE
        int randomIndex = low + rand() % (high - low + 1);
        swap(nums[low], nums[randomIndex]);
        int pivot = nums[low];
        
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
            }
            while(nums[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j) swap(nums[i],nums[j]);
        }
         swap(nums[low],nums[j]);
        return j;
    }
    void quicksort(vector<int>& nums, int low, int high){
        if(low<high){
        int partitionIndex = f(nums, low, high);
        quicksort(nums, low, partitionIndex-1);
        quicksort(nums, partitionIndex+1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        // mergesort(nums, 0, nums.size()-1);
        // return nums;

        // quick sort
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};
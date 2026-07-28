class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        vector<int> visited(n, 0);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int x =  arr[i];
            visited[x-1]++;
        }
        for(int i = 0; i<n; i++){
            if(visited[i]>1){
                ans.push_back(i+1);
            }
        }
        for(int i = 0; i<n; i++){
            if(visited[i]==0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
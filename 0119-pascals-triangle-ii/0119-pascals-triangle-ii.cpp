class Solution {
public:
    vector<int> genrow(int row){
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(ans);
        for(int col = 1; col<row; col++){
            ans = ans*(row-col);
            ans = ans/(col);
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<int> getRow(int rowIndex) {
       return  genrow(rowIndex + 1);
    }
};
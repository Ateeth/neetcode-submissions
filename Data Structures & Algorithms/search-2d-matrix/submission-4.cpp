class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int e = matrix.size() * matrix[0].size() - 1;
        int s = 0 ;
        while(s <= e){
            int m = s + (e - s) / 2;
            int r = m / matrix[0].size();
            int c = m % matrix[0].size();

            if(matrix[r][c] == target) return true;
            if(matrix[r][c] > target) e = m - 1;
            else s = m + 1;
        }
        return false;
    }
};

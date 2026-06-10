class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int i = 0, j = c - 1;
        // while(i < r && j >= 0){
        //     if(matrix[i][j] == target) return true;
        //     if(matrix[i][j] < target){
        //         ++i;
        //     } else { --j;}
        // }

        // return false;
        while(i < r && target > matrix[i][c-1]){
            ++i;
        }

        int s = 0;
        int e = c-1;

        if(i == r) return false;
        while(s <= e){
            int m = s + (e - s) / 2;
            if(matrix[i][m] == target) return true;
            if(matrix[i][m] < target) s = m + 1;
            else e= m - 1;
        }

        return false;
    }
};

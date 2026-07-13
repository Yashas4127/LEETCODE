class Solution {
public:
    vector<vector<int>> generateMatrix(int m) {
        vector<vector<int>>matrix(m,vector<int>(m));
        
        int top = 0, bottom = m - 1, left = 0, right = m - 1;
        int num=1;
        int total=m*m;
        while (num<=total) {
            for (int i = left; i <= right; i++) {
                matrix[top][i]=num++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                matrix[i][right]=num++;
            }
            right--;
            if (top <= bottom) //(if rows remain)
            {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i]=num++;
                }
            }
            bottom--;
            if (left <= right) //(if colms remain)
            {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left]=num++;
                }
            }
            left++;
        }
        return matrix;
    }
};
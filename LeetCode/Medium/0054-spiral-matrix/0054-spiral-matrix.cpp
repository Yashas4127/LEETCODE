class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();    // rows
        int m = matrix[0].size(); // cols
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        vector<int> temp;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                temp.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                temp.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) //(if rows remain)
            {
                for (int i = right; i >= left; i--) {
                    temp.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if (left <= right) //(if colms remain)
            {
                for (int i = bottom; i >= top; i--) {
                    temp.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return temp;
    }
};

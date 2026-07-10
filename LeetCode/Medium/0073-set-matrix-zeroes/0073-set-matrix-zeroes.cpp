class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //For the 1st row keep it outside box
        int col0 = 1;

        //Marker 
        //1st row and col 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0) {
                        col0 = 0;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

            //Mark it zero acconding marker
            //But start from 1 to n and 1 to m 
            //Because when we start from 1st col it act as marker for others it may get mismatch
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[i][j] != 0) {
                        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
            //Now do it 0 row and col
            if (matrix[0][0] == 0) {
                for (int i = 0; i < m; i++) {
                    matrix[0][i] = 0;
                }
            }
            if (col0 == 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][0] = 0;
                }
            }
        
    }
};
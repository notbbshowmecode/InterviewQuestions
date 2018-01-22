class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> result;
        for (int start = 0; 2 * start < rows && 2 * start < cols; start++) {
            int rend = rows - start - 1;
            int cend = cols - start - 1;

            if (start == rend && start == cend) {
                result.push_back(matrix[start][start]);
                break;
            }

            if (start == rend) {
                for (int i = start; i <= cend; i++) {
                    result.push_back(matrix[start][i]);
                }
                break;
            }
            if (start == cend) {
                for (int i = start; i <= rend; i++) {
                    result.push_back(matrix[i][start]);
                }
                break;
            }

            for (int i = start; i < cend; i++) {
                result.push_back(matrix[start][i]);
            }
            for (int i = start; i < rend; i++) {
                result.push_back(matrix[i][cend]);
            }
            for (int i = cend; i > start; i--) {
                result.push_back(matrix[rend][i]);
            }
            for (int i = rend; i > start; i--) {
                result.push_back(matrix[i][start]);
            }
        }
        
        return result;
    }
};
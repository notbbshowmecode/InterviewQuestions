class Solution {
public:
    bool Find(int target, vector<vector<int>> matrix) {
        int row_start = 0;
        int col_start = 0;
        int row_end = matrix.size() - 1;
        int col_end = matrix[0].size() - 1;

        while (row_start <= row_end && col_start <= col_end) {
            int pivot = matrix[row_start][col_end];
            if (target == pivot) {
                return true;
            }
            else if (target < pivot) {
                col_end--;
            }
            else {
                row_start++;
            }
        }

        return false;
    }
};

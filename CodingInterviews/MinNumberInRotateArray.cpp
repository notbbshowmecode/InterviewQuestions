class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int start = 0;
        int end = rotateArray.size()-1;
        while (start <= end) {
            int middle = start + (end - start)/2;

            if (middle > start) {
                if (rotateArray[middle] < rotateArray[middle-1]) {
                    return rotateArray[middle];
                }
                if (rotateArray[middle] >= rotateArray[start]) {
                    start = middle;
                }
            }
            if (middle < end) {
                if (rotateArray[middle] > rotateArray[middle+1]) {
                    return rotateArray[middle+1];
                }
                if (rotateArray[middle] < rotateArray[end]) {
                    end = middle;
                }
            }
        }
        return 0;
    }
};

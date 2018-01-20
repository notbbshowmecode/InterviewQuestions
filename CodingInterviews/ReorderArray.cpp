class Solution {
public:
    void reOrderArray(vector<int> &array, bool (*condition)(int)) {
        vector<int>::iterator p = array.begin();
        while (p != array.end()) {
            while (p != array.end() && condition(*p)) {
                p++;
            }
            if (p == array.end()) {
                break;
            }

            vector<int>::iterator q = p + 1;
            while (q != array.end() && !condition(*q)) {
                q++;
            }
            if (q == array.end()) {
                break;
            }

            int temp = *q;
            vector<int>::iterator r = q;
            while (r != p) {
                *r = *(r - 1);
                r--;
            }
            *p = temp;
        }
    }

    static bool isOdd(int x) {
        return (x & 1) == 1;
    }

    void reOrderArray(vector<int> &array) {
        reOrderArray(array, isOdd);
    }
};
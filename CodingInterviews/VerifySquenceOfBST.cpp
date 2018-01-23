class Solution {
public:
    bool VerifySquenceOfBST(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return false;
        }

        vector<int>::iterator root = end - 1;

        vector<int>::iterator p = begin;
        while (*p < *root) {
            p++;
        }

        vector<int>::iterator q = p;
        while (*q > *root) {
            q++;
        }

        if (q != root) {
            return false;
        }

        bool left = false;
        if (p == begin || p - 1 == begin) {
            left = true;
        }
        if (!left) {
            left = VerifySquenceOfBST(begin, p);
        }

        bool right = false;
        if (p == root || p + 1 == root) {
            right = true;
        }
        if (!right) {
            right = VerifySquenceOfBST(p, root);
        }
        
        return left && right;
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST(sequence.begin(), sequence.end());
    }
};
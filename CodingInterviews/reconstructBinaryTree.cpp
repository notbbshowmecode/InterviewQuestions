/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(
        vector<int>::iterator pbegin, vector<int>::iterator pend, 
        vector<int>::iterator ibegin, vector<int>::iterator iend
    ) {
        int value = *pbegin;
        TreeNode* node = new TreeNode(value);

        vector<int>::iterator p = pbegin + 1;
        vector<int>::iterator i = ibegin;
        int offset = 0;
        while (i != iend) {
            if (*i == value) {
                break;
            }
            i++;
            offset++;
        }

        if (i != ibegin) {
            node->left = reConstructBinaryTree(p, p+offset, ibegin, i);
        }
        if (i != iend-1) {
            node->right = reConstructBinaryTree(p+offset, pend, i+1, iend);
        }
        return node;
    }

    TreeNode* reConstructBinaryTree(vector<int> preorder, vector<int> inorder) {
        return reConstructBinaryTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
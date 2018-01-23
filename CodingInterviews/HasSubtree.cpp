/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        
        if (pRoot1->val != pRoot2->val) {
            return false;
        }

        bool left = false;
        if (pRoot2->left == nullptr) {
            left = true;
        }
        if (!left) {
            left = isSubtree(pRoot1->left, pRoot2->left);
        }

        bool right = false;
        if (pRoot2->right == nullptr) {
            right = true;
        }
        if (!right) {
            right = isSubtree(pRoot1->right, pRoot2->right);
        }

        return left && right;
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        if (pRoot1->val == pRoot2->val && isSubtree(pRoot1, pRoot2)) {
            return true;
        }
        if (HasSubtree(pRoot1->left, pRoot2)) {
            return true;
        }
        if (HasSubtree(pRoot1->right, pRoot2)) {
            return true;
        }

        return false;
    }
};
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
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr) {
            return false;
        }
        
        if (pRoot1->val != pRoot2->val) {
            return false;
        }

        return isSubtree(pRoot1->left, pRoot2->left)
               && isSubtree(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }

        if (isSubtree(pRoot1, pRoot2)) {
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
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
    void Convert(TreeNode* root, TreeNode* &head, TreeNode* &tail) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr) {
            head = root;
        }
        else {
            TreeNode* leftHead = root->left;
            TreeNode* leftTail = root->left;
            Convert(root->left, leftHead, leftTail);

            root->left = leftTail;
            leftTail->right = root;

            head = leftHead;
        }

        if (root->right == nullptr) {
            tail = root;
        }
        else {
            TreeNode* rightHead = root->right;
            TreeNode* rightTail = root->right;
            Convert(root->right, rightHead, rightTail);

            root->right = rightHead;
            rightHead->left = root;

            tail = rightTail;
        }
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }

        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;
        Convert(pRootOfTree, head, tail);
        return head;
    }
};
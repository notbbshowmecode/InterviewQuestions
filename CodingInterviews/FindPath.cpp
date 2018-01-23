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
    void FindPath(
        TreeNode* root, int number, 
        int sum, vector<int> &path, 
        vector<vector<int> > &paths
    ) {
        if (root == nullptr) {
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        if (sum == number && root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        }

        if (root->left != nullptr) {
            FindPath(root->left, number, sum, path, paths);
        }
        if (root->right != nullptr) {
            FindPath(root->right, number, sum, path, paths);
        }

        path.pop_back();
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        vector<vector<int> > paths;

        FindPath(root, expectNumber, 0, path, paths);

        return paths;
    }
};
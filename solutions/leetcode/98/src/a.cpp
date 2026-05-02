#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, false, 0, false, 0);
  }

private:
  bool isValidBST(TreeNode *root, bool setl, int lb, bool setu, int ub) {
    if (root == nullptr) {
      return true;
    }

    if (setl && root->val <= lb) {
      return false;
    }

    if (setu && root->val >= ub) {
      return false;
    }

    return isValidBST(root->left, setl, lb, true,
                      setu ? min(ub, root->val) : root->val) &&
           isValidBST(root->right, true, setl ? max(lb, root->val) : root->val,
                      setu, ub);
  }
};

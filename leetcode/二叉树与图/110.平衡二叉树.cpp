// 题目：平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 后序遍历，遍历某个节点的左、右子节点后，
// 根据左、右子节点的深度判断是不是平衡，并得到当前节点的深度
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
    bool isBalanced(TreeNode* root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int left = 0, right = 0;
        if (isBalanced(root->left, left) && isBalanced(root->right, right)) {
            int diff = left - right;
            if (diff <= 1 && diff >= -1) {
                depth = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
};

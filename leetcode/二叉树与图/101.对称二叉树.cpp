/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
private:
    bool isSymmetric(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot1 && !pRoot2) return true;
        if (!pRoot1 || !pRoot2) return false;
        if (pRoot1->val != pRoot2->val) return false;
        return isSymmetric(pRoot1->left, pRoot2->right)
            && isSymmetric(pRoot1->right, pRoot2->left);
    }
};
// @lc code=end


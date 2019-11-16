/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL && t != NULL) return false;
        return isSametree(s, t)
            || isSubtree(s->left, t)
            || isSubtree(s->right, t);
    }
private:
    bool isSametree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        return s && t
               && s->val == t->val
               && isSametree(s->left, t->left)
               && isSametree(s->right, t->right);
    }
};
// @lc code=end


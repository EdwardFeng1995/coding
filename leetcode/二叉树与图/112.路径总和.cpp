/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 * 思路：递归
 */
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        sum -= root->val;
        if (!root->left && !root->right && sum == 0) {
            return true;
        }
        if (root->left) {
            if (hasPathSum(root->left, sum)) {
                return true;
            }
        }
        if (root->right) {
            if (hasPathSum(root->right, sum)) {
                return true;
            }
        }
        return false;
    }
};


/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        stack<TreeNode*> S;
        TreeNode* cur = root;
        while (cur || !S.empty()) {
            while (cur) {
                re.push_back(cur->val);
                S.push(cur);
                cur = cur -> left;
            }
            cur = S.top();
            S.pop();
            cur = cur->right;
        }
        return re;
    }

};


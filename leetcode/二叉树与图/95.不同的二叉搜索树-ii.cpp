/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 * 思路：若以第i个点为根，则[1,i-1]的点一定位于左子树，[i+1,n]位于右子树
 * 对与[1,i-1]递归，生成根节点i所有可能的左子树
 * 对于[i+1,n]递归，生成根节点i所有可能的右子树
 * 然后连起来就行
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> re;
        if (n == 0) {
            return re;
        }
        re = generate(1,n);
        return re;
    }
private:
    vector<TreeNode*> generate(int begin, int end) {
        vector<TreeNode*> re;
        if (begin > end) {
            re.push_back(NULL);
            return re;
        }
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> left_trees = generate(begin, i-1);
            vector<TreeNode*> right_trees = generate(i+1, end);
            for (auto l : left_trees) {
                for (auto r : right_trees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    re.push_back(root);
                }
            }
        }
        return re;
    }
};


/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 * 思路1：
 * 一个节点的祖先一定是是能遍历到该节点的路径上的节点，
 * 遍历搜索至该节点就停止，遍历过程中遇到的都是该节点的祖先，
 * 求得两个节点各自的祖先，然后遍历找到最后一个相同的节点就是最近公共祖先
 *
 * 思路2：
 * 两个节点p,q分为两种情况：
 *  * p和q在相同子树中
    * p和q在不同子树中
 * 从根节点遍历，递归向左右子树查询节点信息，递归终止条件：如果当前节点为空或等于p或q，则返回当前节点
 *  * 递归遍历左右子树，如果左右子树查到节点都不为空，则表明p和q分别在左右子树中，因此，当前节点即为最近公共祖先；
 *  * 如果左右子树其中一个不为空，则返回非空节点。
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
// 思路1：
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        vector<TreeNode*> p_ancestor, q_ancestor;
        vector<TreeNode*> temp1;
        vector<TreeNode*> temp2;
        TreeNode* result;
        int min_size;
        find_ancestor(root, p, p_ancestor, temp1);
        find_ancestor(root, q, q_ancestor, temp2);
        if (p_ancestor.size() >= q_ancestor.size()) {
            min_size = q_ancestor.size();
        } else {
            min_size = p_ancestor.size();
        }
        for (int i = 0; i < min_size; i++) {
            if (p_ancestor[i] == q_ancestor[i]) {
                result = p_ancestor[i];
            }
        }
        return result;
    }

private:
    void find_ancestor(TreeNode* root, TreeNode*p,
                       vector<TreeNode*>& p_ancestor,
                       vector<TreeNode*>& temp) {
        temp.push_back(root);
        if (root == p) {
            p_ancestor = temp;
            return;
        }

        if (root->left) {
            find_ancestor(root->left, p,  p_ancestor, temp);
            temp.pop_back();
        }
        if (root->right) {
            find_ancestor(root->right, p, p_ancestor, temp);
            temp.pop_back();
        }
    }
};


// 思路2：
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
};

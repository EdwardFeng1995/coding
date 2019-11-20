// 题目：二叉树中和为某一直的路径
// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)
//
// 思路：前序遍历，回溯，递归
//

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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> temp;
        if (!root) return res;
        path(root, expectNumber, temp, res);
        return res;

    }
    void path(TreeNode* root, int expectNumber, vector<int>& temp, vector<vector<int>>& result) {
        expectNumber -= root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right && expectNumber == 0) {
            result.push_back(temp);
            return;
        }
        if (root->left) {
            path(root->left, expectNumber, temp, result);
            temp.pop_back();
        }
        if (root->right) {
            path(root->right, expectNumber, temp, result);
            temp.pop_back();
        }
    }
};

// 题目：二叉树的深度
// 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL) return 0;
        int nLeft = TreeDepth(pRoot->left);
        int nRight = TreeDepth(pRoot->right);
        return (nLeft > nRight) ? (nLeft+1) : (nRight+1);
    }
};

// DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int num = 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i = 0;i < n;++i){
                TreeNode *cur = que.front();
                if(cur->left != NULL)
                    que.push(cur->left);
                if(cur->right != NULL)
                    que.push(cur->right);
                que.pop();
            }
            num++;
        }
        return num;
    }
};

// 重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
//
//前序遍历：先访问根节点，再访问左子节点，最后访问右子节点。
//中序遍历：先访问左子节点，再访问根节点，最后访问右子节点。
//后序遍历：先访问左子节点，再访问右子节点，最后访问根节点。
//
//本题在清楚三种遍历的情况下，很容易得出，前序遍历的第一个节点即为根节点，
//然后在中序遍历中找出根节点，中序遍历中根节点的左边节点是树的左子树，
//并记录左边的节点个数i，右边节点为树的右子树；对于前序遍历，根节点后面的i
//个节点是树的左子树，剩余节点为右子树。由此可得到左子树和右子树的前序和中序
//遍历，然后进行递归，即可得出结果
//
//
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty())
            return nullptr;
       
        /*
        auto iteb_p = pre.begin();
        auto itee_p = pre.end() - 1;
        auto iteb_v = vin.begin();
        auto itee_v = vin.end() - 1;
        */

        int rootValue = pre[0];

        //此处用new是因为要分配内存，如果只是TreeNode* root定义变量，则只是一个指针
        TreeNode* root = new TreeNode(rootValue);           
        /*if(iteb_p == itee_p) {
            if(iteb_v == itee_v && *iteb_p == *itee_v)
                return root;
            else
                throw std::exception("Invaild input.");
        }*/
        
        auto rootvin = find(vin.begin(), vin.end(), rootValue);
        //if(!rootvin)
        //    throw std::exception("Incaild input.");
        
        int i = rootvin - vin.begin();
        vector<int> pre_left, vin_left, pre_right, vin_right;
        
        for(int it = 1; it != pre.size(); it++) {
            if(it <= i)
                pre_left.push_back(pre[it]);
            else
                pre_right.push_back(pre[it]);
        }
        
        for(int it = 0; it != vin.size(); it++) {
            if(it < i)
                vin_left.push_back(vin[it]);
            else if(it == i)
                ;
            else
                vin_right.push_back(vin[it]);
        }

        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        
        return root;
       
    }      
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in) {
        if (leftpre > rightpre || leftin > rightin) return NULL;
        TreeNode *root = new TreeNode(pre[leftpre]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != pre[leftpre]) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
        root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
        return root;
    }
};

/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        BST_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) {
            return NULL;
        }
        vector<TreeNode*> node_vec;
        int val = 0;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val*10 + data[i] - '0';
            }
        }
        for (int i = 1; i < node_vec.size(); i++) {
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
private:
    void change_int_to_string (int val, string &str_val) {
        string tmp;
        while (val) {
            tmp += val%10 + '0';
            val = val/10;
        }
        for (int i = tmp.length() - 1; i >= 0; i--) {
            str_val += tmp[i];
        }
        str_val += '#';
    }

    void BST_preorder(TreeNode* node, string &data) {
        if (!node) {
            return;
        }
        string str_val;
        change_int_to_string(node->val, str_val);
        data +=str_val;
        BST_preorder(node->left, data);
        BST_preorder(node->right, data);
    }

    void BST_insert(TreeNode* root, TreeNode* node) {
        if (node->val < root->val) {
            if (root->left) {
                BST_insert(root->left, node);
            } else {
                root->left = node;
            }
        } else {
            if (root->right) {
                BST_insert(root->right, node);
            } else {
                root->right = node;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end


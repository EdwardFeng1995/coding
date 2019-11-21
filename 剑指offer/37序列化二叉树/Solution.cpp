// 题目：序列化二叉树
// 请实现两个函数，分别用来序列化和反序列化二叉树
// 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
// 从而使得内存中建立起来的二叉树可以持久保存。
// 序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），
// 以 ！ 表示一个结点值的结束（value!）。
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if (!root) return "#";
        string r = to_string(root->val);
        r.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret,right);
        return ret; 
    }
    TreeNode* Deserialize(char *str) {
        return decode(str);
    }
private:
    TreeNode* decode(char *&str) {
        if (*str == '#') {
            str++;
            return NULL;
        }
        int num = 0;
        while (*str != ',')
            num = num*10 + (*(str++) - '0');
        TreeNode* root = new TreeNode(num);
        str++;
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
};

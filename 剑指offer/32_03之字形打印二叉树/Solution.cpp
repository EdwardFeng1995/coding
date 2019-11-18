// 题目：之字形打印二叉树
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        stack<TreeNode*> levels[2];
        levels[0].push(pRoot);
        int current = 0;
        int next = 1;
        vector<int> temp;
        while (!levels[0].empty() || !levels[1].empty()) {
            TreeNode* node = levels[current].top();
            levels[current].pop();
            temp.push_back(node->val);
            if (current == 0) {
                if (node->left) levels[next].push(node->left);
                if (node->right) levels[next].push(node->right);
            } else {
                if (node->right) levels[next].push(node->right);
                if (node->left) levels[next].push(node->left);
            }

            if (levels[current].empty()) {
                res.push_back(temp);
                temp.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return res;
    }

};


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        stack<TreeNode*> s1, s2;
        s1.push(pRoot);
        int level = 1;
        while (!s1.empty() || !s2.empty()) {
            int size1 = s1.size();
            int size2 = s2.size();
            vector<int> temp;
            if (level % 2 == 1) {
                while (size1) {
                    TreeNode* node = s1.top();
                    s1.pop();
                    size1--;
                    temp.push_back(node->val);
                    if (node->left) s2.push(node->left);
                    if (node->right) s2.push(node->right);
                }
            } else {
                while (size2) {
                    TreeNode* node = s2.top();
                    s2.pop();
                    size2--;
                    temp.push_back(node->val);
                    if (node->right) s1.push(node->right);
                    if (node->left) s1.push(node->left);
                }
            }
            res.push_back(temp);
            level++;
        }
        return res;
    }

};


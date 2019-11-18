// 题目：分行从上到下打印二叉树
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。


// 思路1
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if (!pRoot) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            int nextlevel = 0;   // 下一层的个数
            int toBePrinted = 1; // 当前层还没有打印的个数
            vector<int> temp;
            while (!q.empty()) {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                    nextlevel++;
                }
                if (node->right) {
                    q.push(node->right);
                    nextlevel++;
                }
                q.pop();
                toBePrinted--;
                if (toBePrinted == 0) {
                    toBePrinted = nextlevel;
                    nextlevel = 0;
                    res.push_back(temp);
                    temp.clear();
                }
            }
            return res;
        }
     
};


// 思路2
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if (!pRoot) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            while (!q.empty()) {
                int size = q.size();
                vector<int> temp;
                while (size) {
                    TreeNode* node = q.front();
                    q.pop();
                    size--;
                    temp.push_back(node->val);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                res.push_back(temp);
            }
            return res;
        }
     
};

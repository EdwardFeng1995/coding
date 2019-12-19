class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left=minDepth(root->left),right=minDepth(root->right);
        return (left && right) ? 1+min(left,right):1+left+right;
    }
};

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0 ;
        queue<TreeNode*> q ;
        q.push(root);
        int currentdeep(0);
        TreeNode* node;
        while(!q.empty()){
            int qsize= q.size();
            currentdeep++;
            for(int i =0;i<qsize;i++){
                TreeNode* node =q.front();
                q.pop();
                if(node->left==NULL&&node->right==NULL){
                    return currentdeep;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

        }
        return currentdeep;
    }

};

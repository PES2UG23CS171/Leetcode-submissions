class Solution {
public:
    pair<int,int> calc(TreeNode* root, int& ans) {
        if(root->left==NULL && root->right==NULL) {
            ans++;
            return {root->val, 1};
        }
        int sum=root->val, c=1;
        if(root->left) {
            auto [ls, lc]=calc(root->left, ans);
            sum+=ls;
            c+=lc;
        }
        if(root->right) {
            auto [rs, rc]=calc(root->right, ans);
            sum+=rs;
            c+=rc;
        }
        if(root->val==sum/c)
            ans++;
        return {sum, c};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        calc(root, ans);
        return ans;
    }
};

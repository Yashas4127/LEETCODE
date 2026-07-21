/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int solve(TreeNode *root ,int &count ){
        if(!root) return -1;
        
        int leftMax=solve(root->left,count);
        int rightMax=solve(root->right,count);

        int maxValue=max({root->val,leftMax,rightMax});

        if(root->val==maxValue){
            count++;
        }

        return maxValue;

    }
    int countDominantNodes(TreeNode* root) {
        int hm=0;
        solve(root,hm);
        return hm;
    }
};
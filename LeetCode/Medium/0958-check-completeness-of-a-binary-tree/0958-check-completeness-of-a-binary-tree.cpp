/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    
    bool isComplete(TreeNode* root, int index, int nodeCount) {
        if (!root)
            return true;
        if (index >= nodeCount)
            return false;
        return isComplete(root->left, 2 * index + 1, nodeCount) &&
               isComplete(root->right, 2 * index + 2, nodeCount);
    }
    bool isCompleteTree(TreeNode* root) {
        int count=countNodes(root);
        int index=0;
        return isComplete(root,index,count);
    }
};
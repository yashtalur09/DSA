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
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);      
    }
    int totSum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+totSum(root->left)+totSum(root->right);
    }
    int avrg(TreeNode* root){
        if(root==NULL) return 0;
        
        int n=countNodes(root);
        int sum=totSum(root);
        return sum/n;
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        if(root->val==avrg(root)){
            ans++;
        }
        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);
        return ans;
    }
};
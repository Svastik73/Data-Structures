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
    int height(TreeNode* root) {  // find height of tree
        if (root == nullptr) return 0;
        else return 1 + max(height(root->left), height(root->right));
    }

    TreeNode* dfs(TreeNode* root, int h, int curh) {
        if (root == nullptr) { // if reached to end node having height less than max height!
            return nullptr;
        } else {
            curh++;  // increase current height by 1
            TreeNode* lef = dfs(root->left, h, curh); //check whether left subtree has that max depth node or not
        
            TreeNode* rig = dfs(root->right, h,curh); // check whether right subtree has max depth node or not

            if (curh == h) {
                return root; // if present node is max depth return it!
            } else if (lef != nullptr && rig != nullptr) {
                return root; // if both left nad right subtree have that "max depth node" return their ancestor!
            } else if (lef != nullptr) {
                return lef;// if left subtree has "max depth node" return the pointer which was generated recursively
            } else if (rig != nullptr) {
                return rig; // apropos to above step!
            } else {
                return nullptr; // if right and left subtree dont have "max depth node" return null!
            }
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int h = height(root);
        int curh = 0;
        TreeNode* ans = dfs(root, h, curh);
        return ans;
    }
};

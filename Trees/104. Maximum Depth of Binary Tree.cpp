class Solution {
public:
     void height(TreeNode *root,int *h){
         if(root==NULL) return ;
         else
         {
             *h=*h+1;
             int tem=*h;
             height(root->left,h); // check max depth at left subtree
             height(root->right,&tem);// check max depth at left subtree
             *h=max(*h,tem); // update h with max depth obtained!
         }
     }
    int maxDepth(TreeNode* root) {
         int h=0;
         height(root,&h);
         return h;
    }
};

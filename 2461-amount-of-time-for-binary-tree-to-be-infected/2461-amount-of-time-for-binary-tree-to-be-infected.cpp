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
 int burn(TreeNode * root,int start,int&timer){
    if(!root)
    return 0;

     if(root->val==start)
     return -1;
     
     int left=burn(root->left,start,timer);
     int right = burn(root->right,start,timer);

      if(left<0){
        // left se brun aya
        timer = max(timer , abs(left)+right);
        return left-1;
      }

      if(right<0){
        timer= max(timer,abs(right)+left);
        return right-1;
      }

      // dono side se kuch mhi aya return maximum height
      return 1+ max(left,right);
     
      }
      void find(TreeNode * root, int start , TreeNode * &burnNode){
    
         if(!root)
         return ;

         if(root->val==start){
            burnNode=root;
            return ;
         }
         find(root->left,start,burnNode);
         find(root->right,start,burnNode);
      }
      int  Height(TreeNode * root){
        if(!root)
        return 0;

        return 1+max(Height(root->left),Height(root->right));
      }
      
    int amountOfTime(TreeNode* root, int start) {
        
        
        // without using the map 

        // at each node check if burn is coming or not else return max height
        int timer=0;
        burn(root,start,timer);

        // find the hirght below that
        TreeNode * burnNode=NULL;
        find(root,start,burnNode);
        int high = Height(burnNode)-1;
        return max(high,timer);

    }
};
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
    int ans=0;
    
    void foo(TreeNode* root,vector<int>& arr,int i)
    {
        if(root->left !=NULL)
        {
            if(root->left->val == arr[i])
            {
                if(i<arr.size()){
                    i++;
                    foo(root->left,arr,i);
                }
                    
            }    
        }
        if(root->right != NULL)
        {
            if(root->right->val == arr[i])
            {
                if(i<arr.size())
                {
                    i++;
                    foo(root->right,arr,i);
                }
                    
            }    
        }
        i--;
        cout<<"i->"<<i<<"  val ->"<<root->left<<endl;
        if(root->left == NULL && root->right == NULL)
        {
            if(i==arr.size()-1)
            {
                ans=1;
            }   
        }
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(arr[0] != root->val)
            return 0;
        
        foo(root,arr,1);
        return ans;
    }
};

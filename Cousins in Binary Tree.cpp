/*
Cousins in Binary Tree
Solution
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.
Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Note:
The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 

Submission Detail
103 / 103 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 11.2 MB
*/


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
    
    int cnt=0,dep1=0;
    int *pre1;
    int *pre2;
    int dep2=0;
    // void depthds(TreeNode* n,int x)
    // {
    //     if(n->left!=NULL)
    //     {
    //         cnt++;
    //         if(n->left->val == x)
    //         {
    //             pre = &(n->val);
    //             dep = cnt;
    //         }   
    //         depthds(n->left,x); 
    //     }
    //     if(n->right !=NULL)
    //     {
    //         cnt++;
    //         if(n->right->val == x)
    //         {
    //             pre = &(n->val);
    //             dep = cnt;
    //         }
    //         depthds(n->right,x); 
    //     }
    //     cnt--;
    // }
    void depthds(TreeNode* n,int x,int y)
    {
        if(n->left!=NULL)
        {
            cnt++;
            if(n->left->val == x)
            {
                pre1 = &(n->val);
                dep1 = cnt;
            }
            if(n->left->val == y)
            {
                pre2 = &(n->val);
                dep2 = cnt;
            }  
            depthds(n->left,x,y); 
        }
        if(n->right !=NULL)
        {
            cnt++;
            if(n->right->val == x)
            {
                pre1 = &(n->val);
                dep1 = cnt;
            }
            if(n->right->val == y)
            {
                pre2 = &(n->val);
                dep2 = cnt;
            }  
            depthds(n->right,x,y); 
        }
        cnt--;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* l1 = root;
        // TreeNode* l2 = root;
        depthds(l1,x,y);
        // int *p1=pre,d1=dep;
        // cnt = 0;
        // depthds(l2,y);
        // int *p2=pre,d2=dep;
        if(pre1!=pre2 && dep1==dep2)
            return true;
        else
            return false;
    }
};

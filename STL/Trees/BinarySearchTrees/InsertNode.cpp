#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode * node =new TreeNode(val);
//         if(!root) return node;
//         TreeNode* ans = root;
//         while(root){
//             if(val>root->val){
//                 if(!root->right){
//                     root->right = node;
//                     break;
//                 }
//                 else{
//                     root = root->right;
//                 }
//             }
//             else{
//                 if(!root->left){
//                     root->left = node;
//                     break;
//                 }
//                 else{
//                     root = root->left;
//                 }
//             }
//         }
//         return ans;

//     }
// };

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
        root=new TreeNode(val);
        return root;
    }
    if(val<root->val)
    {
    root->left=insertIntoBST(root->left,val);
    }
     else if(val > root->val)
        {
            root->right=insertIntoBST(root->right, val);
        }
        
        return root;
        
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution s;
    TreeNode* ans = s.insertIntoBST(root,5);
    cout<<ans->right->left->val;
    return 0;
}
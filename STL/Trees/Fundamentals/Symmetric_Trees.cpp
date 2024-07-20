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


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return symm(root->left,root->right);
    }
private:
    bool symm(TreeNode* leftnode, TreeNode* rightnode){
        if(!leftnode || !rightnode)
            return leftnode == rightnode;
        
        if(leftnode->val != rightnode->val){
            return false;
        }

        return symm(leftnode->left,rightnode->right) && symm(leftnode->right,rightnode->left);
    }   
};
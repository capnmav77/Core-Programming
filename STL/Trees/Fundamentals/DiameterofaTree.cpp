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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxim = 0;
        int temp = finddiam(root,maxim);
        return maxim;
        
    }

private:
    int finddiam(TreeNode*root , int & maxim){
        if(!root){
            return -1;
        }
        int leftlen =1 + finddiam(root->left,maxim);
        int rightlen =1 + finddiam(root->right,maxim);

        int diam = leftlen+rightlen;
        if(diam>maxim) maxim = diam;
        return max(leftlen,rightlen);
    }
};

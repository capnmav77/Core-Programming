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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->val);
        dfs(root,0,ans);
        return ans;

    }

private:
    void dfs(TreeNode* root,int level, vector<int>& ans){
        if(!root){
            return;
        }
        //intuition behind it is simple , we are checking if the level is already present in the ans vector or not
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        if(root->right) dfs(root->right,level+1,ans);
        if(root->left) dfs(root->left,level+1,ans);
        return;
    }
};
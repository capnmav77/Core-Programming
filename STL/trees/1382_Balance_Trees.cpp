#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    void inorder(TreeNode*root , vector<int> &vals){
        if(!root){
            return;
        }
        inorder(root->left , vals);
        vals.push_back(root->val);
        inorder(root->right , vals);
    }

    TreeNode* buildBalancedBST(const vector<int> &elem , int start , int end){
        if(start > end){
            return nullptr;
        }

        int mid = start + (end-start) / 2;
        TreeNode* node = new TreeNode(elem[mid]);
        node -> left = buildBalancedBST(elem,start,mid-1);
        node -> right = buildBalancedBST(elem,mid+1, end);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> Values;
        inorder(root,Values);
        return buildBalancedBST(Values,0,Values.size()-1);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    Solution sol;
    TreeNode* balancedRoot = sol.balanceBST(root);
    return 0;
}
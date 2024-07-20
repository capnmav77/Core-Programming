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
    vector<int> topdownview(TreeNode* root){
        vector<int> ans;
        if(!root) return ans;
        //similar to vertical solution we will use a map to store the vertical order
        map<int,map<int,int>> mapp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            mapp[x][y] = node->val;
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        for(auto& entry:mapp){
            ans.push_back(entry.second.begin()->second);
        }
        return ans;
    }
};

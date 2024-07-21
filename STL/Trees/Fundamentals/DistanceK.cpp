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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        if(k==0) {
            ans.push_back(target->val);
            return ans;
        }
        queue<TreeNode*>q;
        unordered_map<TreeNode* , TreeNode*> Parent;
        unordered_map<TreeNode*, bool> visited;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){ 
                q.push(node->left);
                Parent[node->left] = node;
            }
            if(node->right){ 
                q.push(node->right);
                Parent[node->right] = node;
            }
        }

        int depth = 0;
        q.push(target);
        while(!q.empty() && depth < k){
            int n = q.size();
            for(int i=0 ; i<n ; ++i){
                TreeNode* node = q.front();
                q.pop();
                visited[node] = true;
                if(node->left && visited[node->left]==false){
                    q.push(node->left);
                }
                if(node->right && visited[node->right]==false){
                    q.push(node->right);
                }
                if(Parent[node] && visited[Parent[node]]==false){
                    q.push(Parent[node]);
                }
            }
            depth ++;
            if(depth == k){
                int n = q.size();
                for(int i=0 ; i<n ; ++i){
                    TreeNode* node = q.front();
                    ans.push_back(node->val);
                    q.pop();
                }
            }
        }
        return ans;
    }
};
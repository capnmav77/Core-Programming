#include<iostream>
#include<bits-stdc++.h>

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


// DFS Solution for Vertical Traversal 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        unordered_map<int, vector<pair<int, int>>> mapp;
        dfs(root, 0, 0, mapp);

        // Collect keys from the map and sort them
        vector<int> keys;
        for (auto& entry : mapp) {
            keys.push_back(entry.first);
        }
        sort(keys.begin(), keys.end());

        // Populate ans in sorted order
        for (int key : keys) {
            vector<pair<int, int>>& temp = mapp[key];
            sort(temp.begin(), temp.end(), sortBySecond);

            vector<int> tempo;
            for (auto& elem : temp) {
                tempo.push_back(elem.first);
            }
            ans.push_back(tempo);
        }

        return ans;
    }

private:
    // Comparator function to sort pairs based on the second element
    static bool sortBySecond(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second; // Sort in ascending order of the second element
    }

    // DFS to populate the map with vertical order
    void dfs(TreeNode* root, int vertical, int depth, unordered_map<int, vector<pair<int, int>>>& mapp) {
        if (!root) {
            return;
        }

        mapp[vertical].push_back({root->val, depth});
        dfs(root->left, vertical - 1, depth + 1, mapp);
        dfs(root->right, vertical + 1, depth + 1, mapp);
    }
};

//Jesus christ , this is the BFS solution : 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();

            TreeNode* node = p.first;
            int vert = p.second.first, depth = p.second.second;
            nodes[vert][depth].insert(node->val);
            if(node->left) q.push({node->left,{vert-1,depth+1}});
            if(node->right) q.push({node->right,{vert+1,depth+1}});
            
            q.pop();

        }
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
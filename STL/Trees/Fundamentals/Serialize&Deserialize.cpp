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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) ans.append("#,");
            else{
                ans.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root;
        if(data=="") return NULL;
        stringstream s(data);
        string str ;
        getline(s , str, ',');
        root = new TreeNode(stoi(str));
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;  
            }else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->left = temp;
                q.push(temp);
            }

            getline(s,str,',');
            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
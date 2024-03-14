// 1026. Maximum Difference Between Node and Ancestor
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

// Example 1:


// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
// Example 2:


// Input: root = [1,null,2,null,0,3]
// Output: 3
 

// Constraints:

// The number of nodes in the tree is in the range [2, 5000].
// 0 <= Node.val <= 105



#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

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
int diff = 0;

private:    
    // void display_graph(){
    //     for(auto it = graph.begin() ; it!= graph.end() ; it++){
    //         cout<<it->first<<":";
    //         for(auto val: it->second){
    //             cout<<val<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    // void create_graph(TreeNode * root){
    //     if(!root){
    //         return;
    //     }
    //     if(root->left){
    //         graph[root->val].push_back(root->left->val);
    //     }
    //     if(root->right){
    //         graph[root->val].push_back(root->right->val);
    //     }
    //     create_graph(root->left);
    //     create_graph(root->right);
    // }

    // void create_graph(TreeNode * root , vector<int> parents){
    //     if(!root){
    //         return;
    //     }
    //     if(root->left){
    //         graph[root->val].push_back(root->left->val);
    //         create_graph(root->left);
    //     }
    //     if(root->right){
    //         graph[root->val].push_back(root->right->val);
    //         create_graph(root->right);
    //     }
    // }

    void differ(TreeNode *root , int minVal , int maxVal){
        if(!root){
            return ;
        }
        diff = max(diff , max(abs(minVal - root->val) , abs(maxVal - root->val)));
        maxVal = max(maxVal , root->val);
        minVal = min(minVal , root->val);
        differ(root->left , minVal , maxVal);
        differ(root->right , minVal , maxVal);
    }

    void dfs(TreeNode *root , int minval , int maxval){
        if(!root){
            return ;
        }
        diff = max(diff , max(abs(minval - root->val) , abs(maxval - root->val)));
        minval = min(minval , root->val);
        maxval = max(maxval , root->val);
        dfs(root->left , minval,maxval);
        dfs(root->right , minval,maxval);
    }


public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        int minVal = root->val , maxVal = root->val;
        dfs(root, minVal , maxVal);
        return diff;
    }

};

int main()
{
    Solution s;
    TreeNode * root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);
    cout<<s.maxAncestorDiff(root)<<endl;

    return 0;
}
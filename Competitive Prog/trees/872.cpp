// 872. Leaf-Similar Trees
// Easy
// 3.4K
// 76
// Companies
// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true



#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

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

private: 
    void display(vector<int> &leaves){
        for(int i=0 ; i<leaves.size() ; i++){
            cout<<leaves[i]<<" ";
        }
    }

    void getleaves(TreeNode *root , vector<int> &leaves){
        if(root == nullptr){
            return ; 
        }
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->val);
        }
        else{
            getleaves(root->left , leaves);
            getleaves(root->right , leaves);
        }
    }

    bool compare(vector<int> &leaves1 , vector<int> &leaves2){
        int m = leaves1.size() ; 
        int n = leaves2.size() ;
        if(m!=n) return false;
        for(int i=0 ; i<m ; i++){
            if(leaves1[i] != leaves2[i]){
                return false;
            }
        }
        return true;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2; 
        getleaves(root1 , leaves1);
        // display(leaves1);
        getleaves(root2 , leaves2);
        //compare
        return compare(leaves1 , leaves2);
    }
};


int main()
{
    Solution s;
    return 0;
}
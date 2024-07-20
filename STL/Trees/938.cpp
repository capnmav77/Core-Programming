// 938. Range Sum of BST
// Easy
// 6.8K
// 367
// Companies
// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

// Example 1:


// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.



#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>




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
    int parsetree(TreeNode* root, int low, int high){
        if(root == nullptr){
            return 0;
        }
        int sum =0 ;
        if(root->val >= low && root->val<=high){
            sum+=root->val;
        }
        sum += parsetree(root->left , low ,high); 
        sum += parsetree(root->right , low , high);
        return sum ; 
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return parsetree( root ,  low ,high);
    }
};


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);

    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    std::cout<<s.rangeSumBST(root , 7 , 15)<<std::endl;
    return 0;
}
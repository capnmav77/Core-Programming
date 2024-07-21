#include<iostream>
#include<bits/stdc++.h> 

using namespace std;



class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root) return 0;
        int child = 0;
        if(root->left) child += root->left->data;
        if(root->right) child += root->right->data;
        
        if(child >= root->data){
            root->data = child;
        }
        else{
            if(root->left) root->left->data = root->data;
            if(root->right) root->right->data = root->right;
        }
        
        isSumProperty(root->left);
        isSumProperty(root->right);
        
        int tot =0 ;
        if(root->left) tot += root->left->data;
        if(root->right) tot += root->right->data;
        if(root->left || root->right){
            root->data = tot;
        }
        return tot;
        
    }
};
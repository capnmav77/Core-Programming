// 2385. Amount of Time for Binary Tree to Be Infected
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

 

// Example 1:


// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.
// Example 2:


// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// Each node has a unique value.
// A node with a value of start exists in the tree.


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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

// class Solution {
// unordered_map<int , vector<int> > graph;
// private: 
//     void display(unordered_map<int , vector<int> > graph){
//         for (auto it = graph.begin(); it != graph.end(); ++it) {
//             cout << "Key: " << it->first << ", Values: ";
//             for (auto val : it->second) {
//                 cout << val << " ";
//             }
//             cout << endl;
//         }

//     }

//     void create_graph(TreeNode *root){
//         if(!root){
//             return ;
//         }
//         if(root->left){
//             graph[root->val].push_back(root->left->val);
//             graph[root->left->val].push_back(root->val);
//         }
//         if(root->right){
//             graph[root->val].push_back(root->right->val);
//             graph[root->right->val].push_back(root->val);
//         }
//         create_graph(root->left);
//         create_graph(root->right);
//     }

// public:
//     int amountOfTime(TreeNode* root, int start) {
//         create_graph(root); 
//         //display(graph);
//         //bfs
//         queue<int> q; 
//         q.push(start);
//         int minutesPassed = -1;

//         unordered_set<int> visited;

//         while(!q.empty()){
//             ++minutesPassed;

//             for(int i=q.size() ; i>0 ; --i){

//                 int currentNode = q.front();
//                 q.pop();
//                 visited.insert(currentNode);

//                 for(int adj : graph[currentNode]){
//                     if(visited.find(adj) == visited.end()){
//                         q.push(adj);
//                     }
//                 }
//             }
//         }
//         return minutesPassed;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




 static const int fast_io = [](){
     std::ios_base::sync_with_stdio(false);
     std::cin.tie(nullptr);
     std::cout.tie(nullptr);
     return 0;
 }();
class Solution {
private:
    static int height(TreeNode* n)
    {
        if (!n)
            return 0;
        return 1 + max(height(n->right), height(n->left));
    }
    static pair<bool, int> traverse(TreeNode* n, int targetVal, int& targetSubtreeHeight, int& maxIndirect)
    {
        if (!n)
            return {false, 0};
        else if (n->val == targetVal)
        {
            targetSubtreeHeight = max(height(n->left), height(n->right));
            return {true, 0};
        }
        else
        {
            auto l = traverse(n->left, targetVal, targetSubtreeHeight, maxIndirect);
            auto r = traverse(n->right, targetVal, targetSubtreeHeight, maxIndirect);
            if (l.first)
            {
                // target node found in the left subtree
                maxIndirect = max(maxIndirect, 1 + l.second + r.second);
                return {true, 1 + l.second};
            }
            else if (r.first)
            {
                maxIndirect = max(maxIndirect, 1 + l.second + r.second);
                // target node found in the right subtree
                return {true, 1 + r.second};
            }
            else
            {
                // there is no target in the current tree
                return {false, 1 + max(l.second, r.second)};
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        int targetLeafLen = 0, maxIndirect = 0;
        traverse(root, start, targetLeafLen, maxIndirect);
        return max(maxIndirect, targetLeafLen);
    }
};

int main()
{
    Solution s;
    return 0;
}
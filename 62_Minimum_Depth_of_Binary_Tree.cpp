// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Input: root = [3,9,20,null,null,15,7]
// Output: 2

// Input: root = [2,null,3,null,4,null,5,null,6]
// Output: 5

// int left =  minDepth(root->left) +1;


// solution
// here we are counting nodes at return time 
// in this  approach we will recursively find min depth from the left sub tree and right subtree and than return their min .

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution
// {
// public:
//     int mini(TreeNode *root)
//     {
//         int a;
//         int b;
//         if (root == NULL)
//             return 0;
//         else if (root->left == NULL && root->right == NULL)
//             return 1;

//         if (root->left == NULL)
//             return mini(root->right) + 1;

//         else if (root->right == NULL)
//             return mini(root->left) + 1;

//         else
//         {
//             a = mini(root->left) + 1;
//             b = mini(root->right) + 1;
//         }

//         return min(a, b);
//     }
//     int minDepth(TreeNode *root)
//     {
//         return mini(root);
//     }
// };

class Solution {
public:
    int minDepth(TreeNode* root) {
        
        int sum =0;
        if(root== NULL)
        return 0;
        
        if((root->left) !=  NULL  && (root->right) != NULL )
        sum = min(minDepth(root->left) , minDepth(root->right));
        
           else if((root->left) ==  NULL  && (root->right) != NULL )
               sum  = minDepth(root->right);
        
           else if((root->left) !=  NULL  && (root->right) == NULL )
               sum  = minDepth(root->left);        
        
        return sum +1;
        
    }
    
};

int main()
{
    TreeNode *root = new TreeNode(3, NULL, NULL);
    TreeNode *second = new TreeNode(9, NULL, NULL);
    TreeNode *third = new TreeNode(20, NULL, NULL);
    TreeNode *forth = new TreeNode(15, NULL, NULL);
    TreeNode *fifth = new TreeNode(7, NULL, NULL);

    root->left = second;
    root->right = third;

    third->left = forth;
    third->right = fifth;

    Solution a;

    cout << a.minDepth(root);

    return 0;
}
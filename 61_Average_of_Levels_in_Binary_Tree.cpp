// https://leetcode.com/problems/average-of-levels-in-binary-tree/

// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].


// solution - here we have created 2  queue 
// 1st queue will will node of a level and 2nd queue will contain child off all the node in the first queue(meand it will contain the next level of the tree).
// there will be 2 loops - first loop will iterate all levels of the tree and the loop will iterate all nodes of a level and put their child to the other queue.





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


class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {

        queue<TreeNode *> q;

        q.push(root);
        TreeNode *p = root;

        vector<double> ans;

        while (!q.empty())
        {

            double temp = 0;
            double sum = 0;
            queue<TreeNode *> tempq;

            while (!q.empty())
            {
                p = q.front();
                q.pop();
                sum = sum + p->val;
                temp++;

                if (p->left != NULL)
                    tempq.push(p->left);

                if (p->right != NULL)
                    tempq.push(p->right);
            }
            ans.push_back(sum / temp);

            q = tempq;
        }

        return ans;
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

    vector<double> ans = a.averageOfLevels(root);

    for (double &i : ans)
        cout << i << " ";

    return 0;
}
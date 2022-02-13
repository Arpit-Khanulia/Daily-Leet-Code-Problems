// https://leetcode.com/problems/spiral-matrix/

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = n, u = 0, d = m;

        while (l < r && u < d)
        {
            if (l < r && u < d)
                for (int i = l; i < r; i++)
                    ans.push_back(matrix[u][i]);

            u++;

            if (l < r && u < d)
                for (int i = u; i < d; i++)
                    ans.push_back(matrix[i][r - 1]);

            r--;
            if (l < r && u < d)
                for (int i = r - 1; i >= l; i--)
                    ans.push_back(matrix[d - 1][i]);

            d--;
            if (l < r && u < d)
                for (int i = d - 1; i >= u; i--)
                    ans.push_back(matrix[i][l]);

            l++;
        }

        return ans;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    // vector<vector<int>> array{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> array{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> ans;

    Solution a;
    ans = a.spiralOrder(array);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
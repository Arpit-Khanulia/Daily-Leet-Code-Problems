// https://leetcode.com/problems/set-matrix-zeroes/

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> column;
        vector<int> row;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    column.push_back(j);
                    row.push_back(i);
                }

        for (int c = 0; c < column.size(); c++)
            for (int i = 0; i < m; i++)
                matrix[i][column[c]] = 0;

        for (int r = 0; r < row.size(); r++)
            for (int i = 0; i < n; i++)
                matrix[row[r]][i] = 0;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int m = matrix.size();
    int n = matrix[0].size();

    Solution a;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout<<endl;

    a.setZeroes(matrix);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// method 1 Brute Force | O(n^2) time and O(N) space.

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {

//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int>column;
//         vector<int>row;

//         for(int i = 0 ; i<m ; i++ )
//             for(int j=0; j<n;j++)
//                 if(matrix[i][j]==0)
//                 {
//                     column.push_back(j);
//                     row.push_back(i);
//                 }

//         for(int c =0 ; c< column.size();c++)
//              for(int i=0; i<m ; i++)
//                matrix[i][column[c]]=0;

//            for(int r =0 ; r<row.size();r++)
//              for(int i=0; i<n ; i++)
//                matrix[row[r]][i]=0;

//     }
// };
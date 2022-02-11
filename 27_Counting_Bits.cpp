// https://leetcode.com/problems/counting-bits/

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        int temp, count = 0;
        for (int i = 0; i < n + 1; i++)
        {
            temp = i;
            while (temp != 0)
            {
                temp = temp & (temp - 1);
                count++;
            }
            ans[i] = count;
            count = 0;
        }
        return ans;
    }
};

int main()
{
    vector<int> b;
    Solution a;
    b = a.countBits(5);

    for (int i = 0; i <= 5; i++)
        cout << " " << b[i];

    return 0;
}
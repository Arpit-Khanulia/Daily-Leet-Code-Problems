// https://leetcode.com/problems/climbing-stairs/

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <iostream>
#include<cstring>
using namespace std;

int dp[100000];
class Solution
{
public:
    int cs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cs(n - 1) + cs(n - 2);

        return dp[n];
    }

    int climbStairs(int n)
    {

        memset(dp, -1, sizeof(dp));

        return cs(n);
    }
};

int main()
{

    Solution a;
    cout << a.climbStairs(6);
}
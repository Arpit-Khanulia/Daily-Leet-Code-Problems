#include <bits/stdc++.h>
using namespace std;

// memoization using 2d dp vector .

vector<vector<int>> dp(10000, vector<int>(10000, -1));
class Solution
{
public:
    int count(int m, int n)
    {

        if (n == 1 || m == 1)
            return 1;

        if (dp[m][n] != -1)
            return dp[m][n];
        else
            dp[m][n] = count(m, n - 1) + count(m - 1, n);

        return dp[m][n];
    }

    // without dp

    //     int count (int m , int n )
    // {

    //     if( n ==1 || m== 1)
    //         return 1;

    //     return count(m,n-1) + count(m-1,n);

    // }
    int uniquePaths(int m, int n)
    {

        return count(m, n);
    }
};

int main()
{

    Solution a;
    cout << a.uniquePaths(23, 12);

    return 0;
}
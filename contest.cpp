#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {

        int count = 0, count2 = 0;
        int maximum = -1;
        int m = nums.size() - 1;
        int h = 0;
        vector<int> dp(nums.size() + 10);
        vector<int> dp2(nums.size() + 10);
        vector<int> temp(100000);
        vector<int> ans;

        dp[m] = nums[m];

        for (int m = nums.size() - 1; m > 0; m--)
        {
            dp[m - 1] = dp[m] + nums[m - 1];
        }

        for (h = 0; h < nums.size(); h++)
        {
            dp2[h] = count2;
            if (nums[h] == 0)
                count2++;
        }
        dp2[h] = count2;

        for (int i = 0; i < nums.size(); i++)
        {
            cout << dp[i];
        }
        cout << endl;
        for (int i = 0; i <= nums.size(); i++)
        {
            cout << dp2[i];
        }

        for (int i = 0; i <= nums.size(); i++)
        {

            count = dp[i] + dp2[i];

            if (maximum < count)
            {
                maximum = count;
            }

            temp[i] = count;

            cout << "count for index " << i << " is " << count << endl;
            count = 0;
        }

        cout << maximum;

        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == maximum)
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> a{0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> c;
    Solution b;
    c = b.maxScoreIndices(a);
    cout << endl;

    for (int i = 0; i < c.size(); i++)
        cout << c[i];

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// class Solution
// {
// public:
//     vector<int> maxScoreIndices(vector<int> &nums)
//     {

//         int count = 0, count2 = 0;
//         int maximum = -1;
//         int m = nums.size() - 1;
//         int h = 0;
//         vector<int> dp(nums.size() + 10);
//         vector<int> dp2(nums.size() + 10);
//         vector<int> temp(1000000);
//         vector<int> ans;

//         dp[m] = nums[m];

//         for (int m = nums.size() - 1; m > 0; m--)
//         {
//             dp[m - 1] = dp[m] + nums[m - 1];
//         }

//         for (h = 0; h < nums.size(); h++)
//         {
//             dp2[h] = count2;
//             if (nums[h] == 0)
//                 count2++;
//         }
//         dp2[h] = count2;

//         for (int i = 0; i <= nums.size(); i++)
//         {

//             count = dp[i] + dp2[i];

//             if (maximum < count)
//             {
//                 maximum = count;
//             }

//             temp[i] = count;

//             count = 0;
//         }

//         for (int i = 0; i < temp.size(); i++)
//         {
//             if (temp[i] == maximum)
//                 ans.push_back(i);
//         }

//         return ans;
//     }
// };


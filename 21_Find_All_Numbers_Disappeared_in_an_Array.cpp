// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:

// Input: nums = [1,1]
// Output: [2]

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> temp(nums.size() + 1);
        vector<int> solution;
        temp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
            temp[nums[i]] = 1;

        for (int i = 0; i < nums.size(); i++)
            if (temp[i] == 0)
                solution.push_back(i);

        for (int i = 0; i < solution.size(); i++)
            cout << solution[i];

        return solution;
    }
};

int main()
{

    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    Solution a;
    a.findDisappearedNumbers(nums);
}

// leetcode

// class Solution
// {
// public:
//     vector<int> findDisappearedNumbers(vector<int> &nums)
//     {
//         vector<int> temp(nums.size() + 1);
//         vector<int> solution;
//         temp[0] = 1;

//         for (int i = 0; i < nums.size(); i++)
//             temp[nums[i]] = 1;

//         for (int i = 0; i <= nums.size(); i++)
//             if (temp[i] == 0)
//                 solution.push_back(i);

//         return solution;
//     }
// };
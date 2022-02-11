// https://leetcode.com/problems/contains-duplicate/

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             if (nums[i] = nums[i + 1])
//                 return 1;
//         }
//         return 0;
//     }
// };


class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
   
        for (int i = 0; i < nums.size() ; i++)
        {
      
        }
        return 0;
    }
};

int main()
{
    Solution b;
    vector<int> a{1, 2, 3, 1};
    b.containsDuplicate(a);
}
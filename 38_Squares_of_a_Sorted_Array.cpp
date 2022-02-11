// https://leetcode.com/problems/squares-of-a-sorted-array/

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int size = nums.size() - 1;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (abs(nums[left]) >= abs(nums[right]))
            {
                ans[size] = (nums[left] * nums[left]);
                size--;
                left++;
            }
            else
            {
                ans[size] = (nums[right] * nums[right]);
                size--;
                right--;
            }
        }

        return ans;
    }
};

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{-4, -1, 0, 3, 10};
    vector<int> ans;
    Solution a;

    for (int i = 0; i < array.size(); i++)
    {
        cout << " " << array[i];
    }

    cout << endl;

    ans = a.sortedSquares(array);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
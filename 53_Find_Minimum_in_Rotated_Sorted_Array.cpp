// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

#include <iostream>
#include <vector>
#include <chrono>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0,high = nums.size() - 1;

        if (nums[low] <= nums[high])
            return nums[low];

        if (high == 1)
            return min(nums[low], nums[high]);

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] < nums[mid - 1])
                return nums[mid];

            if (nums[mid] > nums[low])
                low = mid;
            else
                high = mid;
        }

        return nums[high + 1];
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{4, 5, 6, 7, 8, 1, 2};
    Solution a;
    cout << a.findMin(array);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
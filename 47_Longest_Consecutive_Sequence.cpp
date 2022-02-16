// https://leetcode.com/problems/longest-consecutive-sequence/

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

#include <iostream>
#include <vector>
#include <chrono>
#include <limits.h>
#include <algorithm>
using namespace std;

// O(nlogn) time method

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return 0;

        int count = 1, max = INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            if (i + 1 < size)
                if (nums[i + 1] == nums[i] + 1)
                    count++;
                else if (nums[i + 1] == nums[i])
                    continue;
                else
                    count = 1;

            if (max < count)
                max = count;
        }
        return max;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************
    vector<int> array{100, 4, 200, 1, 3, 2};
    Solution a;
    cout << a.longestConsecutive(array);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}


// https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// O(N) time and constant space.
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> ans;

        for (int i = 0; i < size; i++)
        {
            if( nums[abs(nums[i]) - 1]   < 0)
                ans.push_back(abs(nums[i]));
            
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        return ans;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;
    Solution a;
    ans = a.findDuplicates(array);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
// https://leetcode.com/problems/find-the-duplicate-number/

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = 0;
        int hare = 0;
        do
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
            hare = nums[hare];
        } while (hare != tortoise);

        tortoise = 0;
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{3, 1, 3, 4, 2};
    Solution a;
    cout << a.findDuplicate(array);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
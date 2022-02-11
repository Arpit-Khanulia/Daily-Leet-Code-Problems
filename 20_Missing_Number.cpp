// https://leetcode.com/problems/missing-number/

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Example 2:

// Input: nums = [0,1]
// Output: 2
// Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int Xor = 0;
        for (int i = 0; i <= nums.size(); i++)
            Xor = Xor ^ i;
        for (int i = 0; i < nums.size(); i++)
            Xor = Xor ^ nums[i];
        cout << Xor;
        return Xor;
    }
};

int main()
{

    vector<int> a{9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution b;
    b.missingNumber(a);
}

// leetcode

// method 1
// this method will take O(N) time and O(N) space so this is not the optimised solution .

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         vector<int> a(nums.size()+1);
//         for (int i = 0; i < nums.size(); i++)
//             a[nums[i]] = 1;

//         for (int i = 0; i < a.size(); i++)
//             if (a[i] == 0)
//                 return i;

//         return 0;
//     }
// };

// method 2
// we can calculate the sum till n natural number than substract the sum of the element of array with that

// method 3

// XOR

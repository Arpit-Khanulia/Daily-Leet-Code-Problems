// https://leetcode.com/problems/product-of-array-except-self/

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int size = nums.size() - 1;
        int product = nums[size];
        vector<int> ans(nums.size());

        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            ans[i] = nums[i] * ans[i - 1];

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;

        ans[size] = ans[size - 1];

        for (int i = size - 1; i > 0; i--)
        {
            ans[i] = ans[i - 1] * product;
            product = product * nums[i];
        }
        ans[0] = product;

        return ans;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<int> array{-1,1,0,-3,3};
    vector<int> ans;

    Solution a;

    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;

    ans = a.productExceptSelf(array);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// leetcode method 1 O(N) time and O(N) _SPACE

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {

//         int size = nums.size()-1;
//         vector <int> ans(nums.size());
//         vector <int> left(nums.size());
//         vector <int> right(nums.size());

//         left[0]= nums[0];
//         for(int i =1 ; i<nums.size();i++)
//             left[i] = nums[i]*left[i-1];

//         right[size]= nums[size];
//         for(int i =size-1 ; i>=0;i--)
//             right[i] = nums[i]*right[i+1];

//         ans[0]=right[1];
//         ans[size]= left[size-1];
//         for(int i = 1 ; i<size; i++)
//             ans[i]= left[i-1]*right[i+1];

//         return ans;
//     }
// };
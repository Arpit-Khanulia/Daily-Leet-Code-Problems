// https://leetcode.com/problems/single-number/

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]
// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int Xor=0;
        for(int i=0;i<nums.size();i++)
        Xor = Xor ^ nums[i];
        cout<<Xor;
        return Xor;
    }
};

int main()
{
    vector <int> a{4,1,2,1,2};
    Solution b;
    b.singleNumber(a);


}

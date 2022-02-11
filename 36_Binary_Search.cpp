// https://leetcode.com/problems/binary-search/

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1


#include<iostream>
#include<vector>
#include <chrono>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i=0,mid;
        int j= nums.size()-1;
        
       while(i<=j)
        {
            mid = (i+j)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid]<target)
                i = mid+1;
            if(nums[mid]>target)
                j = mid-1;
        }
        return -1;
        
    }
};

int main()
{
auto begin = std::chrono::high_resolution_clock::now();
//*********************************************************************************

   vector <int> array{1,2,3,4,5};
   int target = 4;
   Solution a;
  cout<< a.search(array,target);




//*********************************************************************************
auto end = chrono::high_resolution_clock::now();
auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cout<<endl<<"Time measured: "<< elapsed.count() * 1e-9;
return 0;
}
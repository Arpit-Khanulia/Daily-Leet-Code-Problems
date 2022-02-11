// https://leetcode.com/problems/maximum-subarray/

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// BruteForce

// int maxSubArray(int* nums, int numsSize)
// {

//    int max= INT_MIN;
//    int sum=0;

//    for(int i=0 ; i< numsSize;i++)
//    {
//        for(int j=i ; j<numsSize;j++)
//        {
//            sum = sum +nums[j];

//            if(max<sum)
//            max=sum;

//        }
//        sum =0;
//    }
//    printf(" %d ", max);

// return max;
// }

int maxSubArray(int *nums, int numsSize)
{
    int flag = 0;
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >=0)
            flag = 1;

        if (max < nums[i])
            max = nums[i];
    }
    if (flag == 0)
    {
    printf("_%d",max);
        return max;

    }
     max = 0;
     int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {

        sum = sum + nums[i];

        if (max < sum)
            max = sum;

        if (sum < 0)
            sum = 0;
    }

    printf(" %d ", max);
}

int main()
{
    int nums[5] = {-2,-3,-1,-5,0};
    maxSubArray(nums, 5);

    return 0;
}



// kadanes algorithm c++

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int maxsum= INT_MIN ,currentsum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             currentsum = currentsum + nums[i];
//             maxsum = max(currentsum , maxsum);
            
//             if(currentsum < 0)
//                 currentsum =0;
//         }   
//         return maxsum;
//     }
// };
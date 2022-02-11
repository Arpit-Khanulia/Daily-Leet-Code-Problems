// https://leetcode.com/problems/first-missing-positive/

// Given an unsorted integer array nums, return the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space.

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// 18/1/22 streak maintained


#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int *nums, int numsSize)
{
    int q = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
            q = 1;

        if (nums[i] > numsSize || nums[i] < 1)
        {
            nums[i] = 1;
        }
    }

    if (q == 0)
    {
        printf(" 1 ");
        return 1;
    }

    for (int j = 0; j < numsSize; j++)
    {

        if (nums[nums[j] - 1] > 0)
            nums[abs(nums[j]) - 1] = -nums[abs(nums[j]) - 1];
    }

    printf("\n");

    for (int i = 0; i < numsSize; i++)
    {
        printf(" %d ", nums[i]);
    }
    int flag = 0;

    for (int k = 1; k < numsSize; k++)
    {
        if (nums[k] > 0)
        {
            printf(" \n_%d ", k + 1);
            flag = 1;
            return k + 1;
        }
    }

    if (flag == 0)
    {
        printf(" %d ", numsSize + 1);
        return numsSize + 1;
    }
}

int main()
{

    // int nums[3] = {1, 2, 0};

    // int nums[4] = {3, 4, -1, 1};
    int nums[5] = {7, 8, 9, 11, 12};
    firstMissingPositive(nums, 5);

    return 0;
}

// leetcode

//     int
//     firstMissingPositive(int *nums, int numsSize)
// {
//     int q = 0;
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] == 1)
//             q = 1;

//         if (nums[i] > numsSize || nums[i] < 1)
//         {
//             nums[i] = 1;
//         }
//     }

//     if (q == 0)
//         return 1;

//     for (int j = 0; j < numsSize; j++)
//     {

//         if (nums[abs(nums[j]) - 1] > 0)
//             nums[abs(nums[j]) - 1] = -nums[abs(nums[j]) - 1];
//     }

//     for (int k = 1; k < numsSize; k++)
//     {
//         if (nums[k] > 0)
//             return k + 1;
//     }

//     return numsSize + 1;
// }


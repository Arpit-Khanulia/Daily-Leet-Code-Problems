// https://leetcode.com/problems/kth-distinct-string-in-an-array/

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned.

// 11th of jan streak maintained

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    printf("starts");
    char arr[6][1] = {"d", "b", "c", "b", "c", "a"};
    printf("\narray created");
    int k = 2;
    int arrSize = 6;
    kthDistinct(arr, 6, k);
}

char *kthDistinct(char **arr, int arrSize, int k)
{
    int f = 0;
    int flag = 0;
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            if (!strcmp(arr[i], arr[j]) && i != j)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            f++;
            if (f == k)
                return arr[i];
        }

        flag = 0;
    }
    return "";
}
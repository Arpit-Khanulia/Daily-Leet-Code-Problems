// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// Input: boxes = "110"
// Output: [1,1,3]
// Explanation: The answer for each box is as follows:
// 1) First box: you will have to move one ball from the second box to the first box in one operation.
// 2) Second box: you will have to move one ball from the first box to the second box in one operation.
// 3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.


// 13th of jan streak maintained 


#include <stdio.h>
#include <stdlib.h>

int *minOperations(char *boxes, int *returnSize)
{

    int l = 0;
    while (boxes[l] != NULL)
    {
        l++;
    }

    *returnSize = l;
    int *ans = (int *)calloc(l, sizeof(int));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (boxes[j] == '1')
            {
                ans[i] += abs(i - j);
            }
        }
    }

    for (int k = 0; k < 6; k++)
        printf(" %d ", ans[k]);

    return ans;
}

int main()
{

    char boxes[] = "001011";
    int size = 6;
    minOperations(boxes, &size);

    return 0;
}
// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

// You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.

// You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

// For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

// Return an array answer, where answer[j] is the answer to the jth query.

// // 11th of jan streak maintained 


int *countPoints(int **points, int pointsSize, int *pointsColSize, int **queries, int queriesSize, int *queriesColSize, int *returnSize)
{
    int *sol = (int *)calloc(queriesSize, sizeof(int));
    int distance = 0;
    for (int i = 0; i < queriesSize; i++)
    {
        for (int j = 0; j < pointsSize; j++)
        {
            distance = (pow((queries[i][0] - points[j][0]), 2) + pow((queries[i][1] - points[j][1]), 2));

            if (distance <= queries[i][2] * queries[i][2])
                sol[i]++;
        }
    }
    *returnSize = queriesSize;
    return sol;
}
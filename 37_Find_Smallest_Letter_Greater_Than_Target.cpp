// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

// Note that the letters wrap around.

// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Example 3:

// Input: letters = ["c","f","j"], target = "d"
// Output: "f"

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {

        for (int i = 0; i < letters.size(); i++)
            if (letters[i] > target)
                return letters[i];

        return letters[0];
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************
    vector<char> letters{'a', 'b', 'x'};
    char target = 'y';
    Solution a;
    cout << a.nextGreatestLetter(letters, target);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}



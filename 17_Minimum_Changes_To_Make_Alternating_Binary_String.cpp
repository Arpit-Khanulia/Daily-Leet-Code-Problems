// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

// Example 1:

// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.
// Example 2:

// Input: s = "10"
// Output: 0
// Explanation: s is already alternating.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int count = 0, count2 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' && i % 2 == 0)
                count++;
            if (s[i] == '1' && i % 2 != 0)
                count++;
            if (s[i] == '1' && i % 2 == 0)
                count2++;
            if (s[i] == '0' && i % 2 != 0)
                count2++;
        }
        cout << (count < count2 ? count : count2);
        return (count < count2 ? count : count2);
    }
};

int main()
{
    string b = "01000101111010";
    Solution a;

    a.minOperations(b);
}


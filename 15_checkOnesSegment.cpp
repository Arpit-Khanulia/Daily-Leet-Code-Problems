// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/submissions/

// Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

// Example 1:

// Input: s = "1001"
// Output: false
// Explanation: The ones do not form a contiguous segment.




#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {         
    int b = s.find("01");
    if (b == -1)    return 1;
    else return 0;
          }
};


int main()
{
    string a = "10001";

Solution b;
b.checkOnesSegment(a);

  
}
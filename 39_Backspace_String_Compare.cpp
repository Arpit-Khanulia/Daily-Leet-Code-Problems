// https://leetcode.com/problems/backspace-string-compare/

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

#include <iostream>
#include <vector>
#include <chrono>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        int i= s.size()-1 ,j= t.size()-1;
        int count1=0 , count2=0;

        while(i>=0 || j>=0)
        {
            if(s[i]=='#')
            {
                count1++;
                i--;
            }
            else if(s[i]!='#'  && count1 !=0)
            {
               i= i-count1;
               count1 =0;
            }

            if(t[j]=='#')
            {
                count1++;
            }
            else if(t[j]!='#'  && count2 !=0)
            {
               j= j-count2;
               count2 =0;
            }
            

        }


    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    string s = "y#fo##f", t = "y#f#o##f";
    Solution a;
    a.backspaceCompare(s, t);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// method 1 O(N) space

// class Solution
// {
// public:
//     bool backspaceCompare(string s, string t)
//     {

//         string a, b;

//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '#' && !a.empty())
//             {
//                 a.pop_back();
//             }
//             else if (s[i] != '#')
//             {
//                 a.push_back(s[i]);
//             }
//         }

//         for (int i = 0; i < t.size(); i++)
//         {
//             if (t[i] == '#' && !b.empty())
//             {
//                 b.pop_back();
//             }
//             else if (t[i] != '#')
//             {
//                 b.push_back(t[i]);
//             }
//         }

//         cout << s << endl;
//         cout << t << endl;
//         cout << a << endl;
//         cout << b << endl;

//         return !a.compare(b);
//     }
// };
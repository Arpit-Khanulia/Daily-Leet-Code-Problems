// https://leetcode.com/problems/capitalize-the-title/

// You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

// If the length of the word is 1 or 2 letters, change all letters to lowercase.
// Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
// Return the capitalized title.

// Example 1:

// Input: title = "capiTalIze tHe titLe"
// Output: "Capitalize The Title"
// Explanation:
// Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        

        for (int i = 0; i < title.size(); i++)
        {
            title[i] = tolower(title[i]);
        }

        cout << title << endl;

        int i = 0;
        if (title[2] != ' '  &&  title[1]!=' ')
            title[0] = toupper(title[0]);

        cout << title << endl;

        while (i < title.size())
        {
            if (title[i] == ' ' && title[i + 3] == ' ')
                {i += 3;
                continue;
                }
            if (title[i] == ' ' && title[i + 2] == ' ')
                {i += 2;
                continue;
                }
            else if (title[i] == ' ' && title[i + 3] != ' ')
            {
                title[i + 1] = toupper(title[i + 1]);
            }

            i++;
        }

        if(   title[title.size()-3]==' ')
        title[title.size()-2]=tolower(title[title.size() -2]);
        if(   title[title.size()-2]==' ')
        title[title.size()-1]=tolower(title[title.size() -1]);



        cout << title;
    }
};

int main()
{
    Solution b;
        string a = "r j Rf Ke zgV A u";

    b.capitalizeTitle(a);
}

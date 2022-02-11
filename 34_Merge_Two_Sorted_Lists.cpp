// https://leetcode.com/problems/merge-two-sorted-lists/

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *start = new ListNode;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *p3 = start;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while (p1 != NULL)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != NULL)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        return start->next;
    }
};

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    //*********************************************************************************

    ListNode *list1, *second, *third, *forth;

    list1 = new ListNode(1);
    second = new ListNode(2);
    third = new ListNode(4);
    forth = new ListNode(5);
    list1->next = second;
    // list1->next = NULL;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    ListNode *list2, *second2, *third2, *forth2;

    list2 = new ListNode(2);
    second2 = new ListNode(3);
    third2 = new ListNode(4);
    forth2 = new ListNode(5);
    list2->next = second2;
    //  list1->next = NULL;
    second2->next = third2;
    third2->next = forth2;
    forth2->next = NULL;

    Solution a;
    cout << endl;
    display(a.mergeTwoLists(list1, list2));

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// leetcode method 1
// time O(N) and Space O(N)

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {

//         display(list1);
//         cout << endl;
//         display(list2);

//         ListNode *ans = new ListNode;
//         ListNode *N = ans;

//         while (list1 != NULL || list2 != NULL)
//         {
//             cout<<"*";
//             if (list2 == NULL )
//             {
//                 insert(ans, list1->val);
//                  ans=ans->next;
//                 list1 = list1->next;
//                 continue;
//             }
//             if (list1 == NULL )
//             {
//                 insert(ans, list2->val);
//                  ans=ans->next;
//                 list2 = list2->next;
//                 continue;
//             }
//             if (list1->val < list2->val )
//             {
//                 insert(ans, list1->val);
//                  ans=ans->next;
//                 list1 = list1->next;
//             }
//             else if ( list1->val >= list2->val )
//             {
//                 insert(ans, list2->val);
//                 ans=ans->next;
//                 list2 = list2->next;
//             }
//         }
//         ans=NULL;

//         return N;
//     }
// };

// method 2 using recursion and constant space

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *start = NULL;

//         if (list1 == NULL)
//             return list2;
//         if (list2 == NULL)
//             return list1;

//         if (list1->val < list2->val)
//         {
//             start = list1;
//             start->next = mergeTwoLists(list1->next, list2);
//         }
//         else if (list1->val >= list2->val)
//         {
//             start = list2;
//             start->next = mergeTwoLists(list1, list2->next);
//         }

//         return start;
//     }
// };
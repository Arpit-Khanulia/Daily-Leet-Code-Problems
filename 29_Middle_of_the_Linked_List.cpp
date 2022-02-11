// https://leetcode.com/problems/middle-of-the-linked-list/

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == NULL)
            return head;
        ListNode *hare, *tortoise;
        hare = head;
        tortoise = head;

        while (1)
        {

            if (hare->next == NULL)
            {
                cout << tortoise->val;
                return tortoise;
            }
            if (hare->next->next == NULL)
            {
                cout << tortoise->val;
                return tortoise->next;
            }

            hare = hare->next->next;
            tortoise = tortoise->next;
        }
    }
};

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    //*********************************************************************************

    ListNode *head, *second, *third, *forth, *fifth;

    head = new ListNode(1);
    second = new ListNode(2);
    third = new ListNode(3);
    forth = new ListNode(4);
    fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    Solution a;
    a.middleNode(head);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
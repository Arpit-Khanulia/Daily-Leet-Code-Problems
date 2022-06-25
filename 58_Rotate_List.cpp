// https://leetcode.com/problems/rotate-list/
// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == NULL)
            return NULL;

        ListNode *temp = head;

        int count = 0;

        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        k = k % (count + 1);

        temp->next = head;

        int n = count - k;

        while (n--)
        {
            head = head->next;
        }

        ListNode *ans = head->next;

        head->next = NULL;

        return ans;
    }
};

int main()
{

    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *forth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    Solution a;
    head = a.rotateRight(head, 2);

    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
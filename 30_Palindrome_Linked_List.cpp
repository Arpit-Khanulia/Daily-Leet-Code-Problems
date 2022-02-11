// https://leetcode.com/problems/palindrome-linked-list/

// Given the head of a singly linked list, return true if it is a palindrome.
// Example 1:

// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

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
                return tortoise;
            if (hare->next->next == NULL)
                return tortoise->next;

            hare = hare->next->next;
            tortoise = tortoise->next;
        }
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = middleNode(head);
        ListNode *hare = middle;
        ListNode *dog = middle;
        ListNode *tortoise = NULL;

        while (dog != NULL)
        {
            hare = hare->next;
            dog->next = tortoise;
            tortoise = dog;
            dog = hare;
        }

        while (tortoise != NULL)
        {
            if (tortoise->val != head->val)
                return 0;

            tortoise = tortoise->next;
            head = head->next;
        }

        return 1;
    }
};

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    //*********************************************************************************

    ListNode *head, *second, *third, *forth;

    head = new ListNode(1);
    second = new ListNode(2);
    third = new ListNode(3);
    forth = new ListNode(1);
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    // display(head);

    Solution a;
    cout << a.isPalindrome(head);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
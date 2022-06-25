// https://leetcode.com/problems/reverse-linked-list-ii/

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *temp3 = head;
     int count = 0;
        while(temp3!= NULL)
     {
          temp3  = temp3->next;
        count++;
    }

        if((left == 1 && right ==count ) || (left == right))
        return head;

        ListNode *ans = head;
        ListNode *temp = head;
        ListNode *temp2 = head;

        ListNode *tortoise = NULL;
        ListNode *dog = NULL;
        ListNode *hare = NULL;

        //************************************************************

        if(head == NULL)
        return NULL;

        left = left - 2;
        while (left--)
            temp = temp->next;
        ListNode *front = temp;



        right = right - 1;
        while (right--)
            temp2 = temp2->next;
        ListNode *end = temp2->next;



        temp2->next = NULL;
        dog = temp->next;
        hare = temp->next;

        while (dog != NULL)
        {
            hare = hare->next;
            dog->next = tortoise;
            tortoise = dog;
            dog = hare;
        }


        front->next = tortoise;
        while (tortoise->next != NULL)
            tortoise = tortoise->next;

        tortoise->next = end;

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
    ListNode *ans = a.reverseBetween(head, 2, 4);



     while(ans!= NULL)
        {
            cout<< ans->val<<" ";
            ans = ans->next;
        }

    return 0;
}
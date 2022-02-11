// https://leetcode.com/problems/remove-linked-list-elements/

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

// Example 1:


// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []

#include<iostream>
#include<vector>
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


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
            return NULL;
        
        ListNode* tortoise = head;
        ListNode* start = head;
        head=head->next;
        
        while(head != NULL)
        {
            if(head->val == val)
            {
                head =  head->next;
                tortoise->next = head;
            }
            else
            {
                tortoise = head;
                head = head-> next;
            }
        }
        
        if(start->val == val )
            start = start->next;
        return start;
    }
};


int main()
{
auto begin = std::chrono::high_resolution_clock::now();
//*********************************************************************************

   ListNode *head, *second, *third, *forth;

    head = new ListNode(1);
    second = new ListNode(2);
    third = new ListNode(2);
    forth = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
   
   Solution a;
   display(head);
   cout<<endl;
   display(a.removeElements(head,2));



//*********************************************************************************
auto end = chrono::high_resolution_clock::now();
auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cout<<endl<<"Time measured: "<< elapsed.count() * 1e-9;
return 0;
}
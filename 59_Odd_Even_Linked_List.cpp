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
    ListNode *oddEvenList(ListNode *head) 
    {

        ListNode *o = head;
        ListNode *o1 = head;
        ListNode *e = head->next;
        ListNode *e1 = head->next;

        while (o != NULL && e != NULL)
        {
          
            
                if (o->next != NULL && e->next != NULL)
                {
                    o = o->next->next;
                    e = e->next->next;
                }
                else break;
         
        }

        while (o1->next != NULL)
            o1 = o1->next;

        o1->next = e1;

        return head;
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
    ListNode *ans = a.oddEvenList(head);

    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
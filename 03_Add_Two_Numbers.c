// https://leetcode.com/problems/add-two-numbers/

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// 12th of jan streak maintained

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void traverse(struct ListNode *head)
{
    while (head != NULL)
    {
        printf(" %d ", head->val);
        head = head->next;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{

    struct ListNode *answer = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = answer;
    p->next = NULL;

    int sum = 0, carry = 0, ans = 0, ans2 = 0;

    do
    {

        if (l1 != NULL)
        {
            sum = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum = sum + l2->val;
            l2 = l2->next;
        }

        ans = sum + carry;
        ans2 = ans % 10;

        carry = ans / 10;

        p->val = ans2;

        if (l1 || l2 || carry)
            p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));

        p = p->next;
        sum = 0;

    } while (l1 || l2 || carry);

    printf("\n");

    traverse(answer);

    return answer;
}
int main()
{

    struct ListNode *l1, *second, *third;

    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    second->val = 4;
    third->val = 3;

    l1->next = second;
    second->next = third;
    third->next = NULL;

    // input 2
    //  l1->val = 0;
    //  l1->next = NULL;

    traverse(l1);

    struct ListNode *l2, *se, *th;

    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    se = (struct ListNode *)malloc(sizeof(struct ListNode));
    th = (struct ListNode *)malloc(sizeof(struct ListNode));

    l2->val = 5;
    se->val = 6;
    th->val = 4;

    l2->next = se;
    se->next = th;
    th->next = NULL;

    // input 2

    // l2->val = 0;
    // l2->next = NULL;

    printf("\n");

    traverse(l2);

    addTwoNumbers(l1, l2);

    return 0;
}
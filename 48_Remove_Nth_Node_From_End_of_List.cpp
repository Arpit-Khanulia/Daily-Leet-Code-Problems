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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head->next == NULL)
            return NULL;

                ListNode *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        int no = count - n;
        temp = head;

        if (no == 0)
            return head->next;

        while (--no)
            temp = temp->next;

        temp->next = temp->next->next;

        return head;
    }
};
int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}
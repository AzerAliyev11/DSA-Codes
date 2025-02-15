#include<iostream>

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int hasCycle(ListNode *head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast->next != nullptr)
    {
        if(slow != nullptr)
        {
            slow = slow->next;
        }
        else
        {
            return 0;
        }

        if(fast->next != nullptr)
        {
            fast = fast->next->next;
        }
        else
        {
            return 0;
        }

        if(fast == slow)
            return 1;
    }

    return 0;
}
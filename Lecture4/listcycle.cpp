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

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;


        if(fast == slow)
            return 1;
    }

    return 0;
}
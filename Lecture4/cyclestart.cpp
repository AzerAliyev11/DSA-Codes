#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            ListNode* start = head;
            while(start != slow)
            {
                start = start->next;
                slow = slow->next;
            }

            return start;
        }
    }

    return nullptr;
}
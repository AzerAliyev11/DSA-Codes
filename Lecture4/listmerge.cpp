#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode *l1, ListNode *l2)
{
    ListNode* ans = new ListNode(0);
    ListNode* tmp = ans;

    while(l1 != nullptr && l2 != nullptr)
    {
        if(l1->val < l2->val)
        {
            tmp->next = l1;
            l1 = l1->next;
        }
        else
        {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    if(l1 != nullptr)
    {
        tmp->next = l1;
    }

    if(l2 != nullptr)
    {
        tmp->next = l2;
    }

    return ans->next;
}
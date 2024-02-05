#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int data) //Constructor
    {
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }
};

void PrintElements(Node* head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void AddtoFront(Node** head, int val)
{
    if(*head == NULL)
    {
        *head = new Node(val);
        return;
    }

    Node* n = new Node(val);
    n->next = *head;
    *head = n;
}

void AddtoBack(Node** head, int val)
{
    if(*head == NULL)
    {
        *head = new Node(val);
        return;
    }

    Node* n = new Node(val);
    Node* tmp = *head;

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
    return;
}

void AddtoLoc(Node** head, int loc, int val) //loc ->index
{
    if(*head == NULL)
        *head = new Node(val);

    int i = 0;
    Node* curr = *head;
    Node* prev = NULL;
    while(curr != NULL)
    {
        if(i == loc)
        {
            if(prev == NULL)
            {
                AddtoFront(head, val);
                return;
            }
            prev->next = new Node(val);
            prev->next->next = curr;
            return;
        }
        i++;
        prev = curr;
        curr = curr->next;
    }

    AddtoBack(head, val);
}

void RemoveFromFront(Node** head)
{
    if(*head == NULL)
        return;

    *head = (*head)->next;
}

void RemoveFromBack(Node** head)
{
    if(*head == NULL)
        return;

    if((*head)->next == NULL)
    {
        *head = NULL;
        return;
    }

    Node* tmp = *head;
    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

int main()
{
    LinkedList* list = new LinkedList();

    // list->head = new Node(5);
    // list->head->next = new Node(6);
    // You can also do like above

    AddtoBack(&list->head, 3);
    PrintElements(list->head);

    AddtoFront(&list->head, 11);
    PrintElements(list->head);

    RemoveFromBack(&list->head);
    PrintElements(list->head);

    RemoveFromBack(&list->head);
    PrintElements(list->head);

    AddtoFront(&list->head, 12);
    PrintElements(list->head);

    AddtoLoc(&list->head, 4, 60);
    PrintElements(list->head);
}


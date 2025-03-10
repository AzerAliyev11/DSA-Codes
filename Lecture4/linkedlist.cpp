#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = nullptr;
    }
};

int ListSize(Node* head)
{
    int count = 0;
    while(head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

void PrintElements(Node* head)
{
    while(head) //head != nullptr
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void AddToFront(Node** head, int val)
{
    Node* newNode = new Node(val);

    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void RemoveFromFront(Node** head)
{
    if(*head == nullptr)
        return;
    
    *head = (*head)->next;
}

void AddToBack(Node** head, int val)
{
    Node* newNode = new Node(val);
    if(*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node* tmp = *head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void RemoveFromBack(Node** head)
{
    if(*head == nullptr)
        return;

    if((*head)->next == nullptr)
    {
        *head = nullptr;
        return;
    }

    Node* tmp = *head;
    while(tmp->next->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = nullptr;
}

void AddToLocation(Node** head, int val, int loc)
{
    int sizeofList = ListSize(*head);

    if(loc == 0)
    {
        AddToFront(head, val);
        return;
    }

    if(loc >= sizeofList)
    {
        AddToBack(head, val);
        return;
    }

    int currentIndex = 0;
    Node* tmp = *head;
    while(currentIndex != loc - 1)
    {
        tmp = tmp->next;
        currentIndex++;
    }

    Node* newNode = new Node(val);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

int main()
{
    LinkedList* list = new LinkedList();
    AddToBack(&list->head, 1);
    AddToBack(&list->head, 2);
    AddToBack(&list->head, 3);
    AddToBack(&list->head, 4);

    AddToLocation(&list->head, 7, 2);
    AddToLocation(&list->head, 21, 0);
    AddToLocation(&list->head, 33, 10);

    PrintElements(list->head);
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};


void Insert(Node * &head, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        return ;
    }

    Node* temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;

    temp -> next = newNode;

}

void display (Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " -> " ;
        temp = temp -> next;
    }

}


Node* reverse(Node* head)
{
    if(head == NULL)
        return NULL;
    
    Node* curr = head;
    Node* temp = NULL;

    while(head != NULL)
    {
        head = head -> next;
        curr -> next = temp;
        temp = curr;
        curr = head;

    }
    cout << temp -> data <<endl;
    return temp;
}

int main()
{
    Node* head = NULL;
    Node*temp = NULL;
    int data;
    cout << "Enter data" << endl;
    while(true)
    {
        cin  >> data;
        if(data == -1)
            break;
       Insert(head, data); 
    }

    display(head);
    temp = reverse(head);
    display(temp);
    
    return 0;
}
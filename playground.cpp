#include <iostream>
#include <vector>
#include <algorithm>
#include "unordered_map"

using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "no node defined" << endl;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void deleteNode(Node *&head, int val)
{
    Node *temp = NULL;
    temp->next = head;

    while (temp->next->data == val)
    {
        Node *tempptr = temp->next->next;
        delete temp->next;
        temp->next = tempptr;
        break;
    }
}
void remove(int *arr, int size)
{
    // sort(arr.begin(),arr.end());

    unordered_map<int, bool> val(size);

    for (int i = 0; i < size; i++)
    {

        if (val.find(arr[i]) == val.end())
        {
            cout << arr[i] << " ";
        }

        val[arr[i]] = true;
    }
}

int main()
{

    int arr[11] = {1, 2, 3, 4, 3, 4, 2, 4, 2, 5, 0};

    remove(arr, 11);

    // Node *head = new Node(1);
    // Node *second = new Node(2);
    // Node *third = new Node(3);
    // head->next = second;
    // second->next = third;

    // print(head);

    // deleteNode(head, 2);
    // print(head);

    return 0;
}
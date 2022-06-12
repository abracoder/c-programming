#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode *next):val(x),next(next){}
};
class Node{
    public:
        int data;
        Node *next;
};
void printList(Node *n){
    while( n!= NULL){
        cout<< n->data <<"  " ;
        n=n->next;
    }
    cout<<endl;
}
class Solution{
    public:
            Node* reverseList(Node *head){  // function to reverse the linked list;
                Node *newhead = NULL;
                while (head !=NULL){
                    Node *next= head->next;
                    head->next=newhead;
                    newhead=head;
                    head=next;
                }
                return newhead;
            }

            Node *reverseLL(Node* head){
                Node* prev=NULL;
                Node* next=NULL;
                while(head!=NULL){
                    next=head->next;
                    head->next=prev;
                    prev=head;
                    head=next;
                }
            }

            // function to remove nth node from the end of the linked list;
            Node* removeNthNodeFromEnd(Node *head, int n){
                cout<< "inside remove funtion from end\n";
                Node *start = new Node();
                start->next=head;
                Node *fast=start;
                Node *slow=start;

                for (int i=1;i<=n;i++){
                    fast=fast->next;
                }
                Node *temp=new Node();
                while(fast->next != NULL){
                    fast=fast->next;
                    slow=slow->next;
                    temp=slow;
                }
                cout<< temp<<endl;
                slow->next=slow->next->next;
                return start->next;
            }
            // function to find middle node
            Node* middleLL(Node *head){
                Node *slow=head, *fast=head;

                while(fast !=NULL && fast->next != NULL){
                    slow=slow->next;
                    fast=fast->next->next;
                }
                cout<< slow<<endl;
                return slow;

            }

            // funtion to merge two linked list without the use of third linked list in sorted manner;

            Node * mergeList( Node* l1, Node* l2){
                if(l1==NULL) return l2;
                if(l2 == NULL) return l1;
                if(l1->data >= l2->data) swap(l1,l2);
                Node* res=l1;
                while( l1 != NULL && l2 !=NULL){
                    Node * tmp=NULL;
                    while(l1 != NULL && l1->data <= l2->data){
                        tmp=l1;
                        l1=l1->next;

                    }
                tmp->next=l2;
                swap(l1,l2);


                }
            return res;
            }

            /// function to add two linked list
            Node * addTwoLL(Node *l1,Node *l2){
                cout<< "inside add function"<<endl;
                Node *dummy = new Node();
                Node *temp = dummy;
                int carry=0;
                while(l1!=NULL||l2!=NULL||carry){
                    int sum=0;
                    if(l1!=NULL){
                        sum+=l1->data;
                        l1=l1->next;

                    }
                    if(l2!=NULL){
                        sum+=l2->data;
                        l2=l2->next;

                    }

                    sum+=carry;
                    carry=sum/10;
                    Node* node= new Node();
                    node->data=sum%10;
                    temp->next=node;
                    temp=temp->next;


                }
                return dummy->next;
            }

            // check if the linked list contain cycle;

            bool hasCycle(Node *head){
            if(head==NULL || head->next == NULL){
                return false;
            }
            Node *fast= head,*slow=head;
            while(fast->next && fast->next->next){
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow)return true;

            }
            return false;

            }
            //.. check for pallindrom in a linked list;

            bool isPallindrome(Node* head){
                if(head==NULL || head->next==NULL)return true;

                Node *fast=head,*slow=head;
                // finding middle node  of the linked list
                while(fast->next&&fast->next->next){
                    fast=fast->next->next;
                    slow=slow->next;

                }
                // reversing the nodes after the middle node
                slow->next=reverseList(slow->next);
                slow=slow->next;
                // checking for pallindrome
                while(slow!=NULL){
                    if(slow->data!=head->data){
                        return false;
                    }
                    head=head->next;
                    slow=slow->next;

                }
                return true;
            }

            /// reverse node in k group of a linked list;

            Node *reverseKgroups(Node *head,int k){
                if(head==NULL || k==1) return head;

                Node *dummy= new Node();
                dummy->data=0;
                dummy->next=head;
                Node *curr=dummy->next,*next=dummy->next, *prev=dummy->next;
                int count=0;
                while(curr->next!=NULL){
                    curr=curr->next;
                    count++;

                while(count>=k){
                    curr=prev->next;
                    next=curr->next;
                    for(int i=1; i<k;i++){
                        curr->next=next->next;
                        next->next=prev->next;
                        prev->next=next;
                        next=curr->next;
                    }
                    prev=curr;
                    count-=k;
                }
                return dummy->next;
            }
            // finding the starting point of the cycle in the linked list.

};


int main(){

    Node* head = NULL;
    Node* head1= NULL;

    Node* second = NULL;
    Node* third = NULL;
    Node * fourth = NULL;
    Node * fifth =NULL;
    Node * sixth= NULL;


    // allocate 3 nodes in the heap
    head = new Node();
    head1=new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth =new Node();
    sixth= new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = fourth;
    fourth->data=4;
    fifth->data=5;
    sixth->data=6;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;


    head1->data = 0; // assign data in first node
    head1->next = second; // Link first node with second

    second->data = 3; // assign data to second node
    second->next = third;

    third->data = 2; // assign data to third node
    third->next = fourth;
    fourth->data=6;
    fifth->data=4;
    sixth->data=5;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;

    cout<< "printing linked list data values"<<endl;

    printList(head);
    printList(head1);
    // cout << "printing reverse Link list"<< endl;
    Solution obj;
    // // cout<< obj;
    // printList(obj.reverseList(head));

    // cout<< "removing 2nd node from end\n ";

    // printList(obj.removeNthNodeFromEnd(head,2));

    // cout<<obj.middleLL(head)->data;

    // printList(obj.mergeList(head,head));
    printList(obj.addTwoLL(head1,head));






    return 0;

}
